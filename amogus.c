#define FUSE_USE_VERSION 31
#define _FILE_OFFSET_BITS 64

#include <cuse_lowlevel.h>
#include <fuse_opt.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void amogus_open(fuse_req_t req, struct fuse_file_info *fi)
{
  fuse_reply_open(req, fi);
}

static void amogus_read(fuse_req_t req, size_t size, off_t off,
                        struct fuse_file_info *fi)
{
  fuse_reply_buf(req, "amogus\n", size > 7 ? 7 : size);
}

static const struct cuse_lowlevel_ops amogus_clop = {
    .open = amogus_open,
    .read = amogus_read,
};

int main(int argc, char **argv)
{
  const char *cusearg[] = {"amogus", "-f", "/dev/cuse"};
  const char *devarg[] = {"DEVNAME=amogus"};

  struct cuse_info ci;
  memset(&ci, 0x00, sizeof(ci));
  ci.flags = CUSE_UNRESTRICTED_IOCTL;
  ci.dev_info_argc = 1;
  ci.dev_info_argv = devarg;

  return cuse_lowlevel_main(3, (char **)&cusearg, &ci, &amogus_clop, NULL);
}
