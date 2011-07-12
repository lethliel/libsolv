#include "pool.h"

void *solv_chksum_create(Id type);
void *solv_chksum_create_from_bin(Id type, const unsigned char *buf);
void solv_chksum_add(void *handle, const void *data, int len);
Id solv_chksum_get_type(void *handle);
int solv_chksum_isfinished(void *handle);
const unsigned char *solv_chksum_get(void *handle, int *lenp);
void *solv_chksum_free(void *handle, unsigned char *cp);
const char *solv_chksum_type2str(Id type);
Id solv_chksum_str2type(const char *str);

static inline int solv_chksum_len(Id type)
{
  switch (type)
    {
    case REPOKEY_TYPE_MD5:
      return 16;
    case REPOKEY_TYPE_SHA1:
      return 20;
    case REPOKEY_TYPE_SHA256:
      return 32;
    default:
      return 0;
    }
}
