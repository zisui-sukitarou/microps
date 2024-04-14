#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <sys/time.h>

#include "net.h"
#include "dummy.h"
#include "util.h"
#include "platform.h"

static int dummy_transmit(struct net_device *dev, uint16_t type, const uint8_t *data, size_t len, const void *dst){
    debugf("dev=%s, type=0x%04x, len=%zu", dev->name, type, len);
    debugdump(data, len);
    /* drop data */
    return 0;
}

static struct net_device_ops dummy_ops = {
    transmit: dummy_transmit,
};

struct net_device *dummy_init(){
    struct net_device *dev;
    dev = net_device_alloc();
    if (!dev) {
        errorf("net_device_alloc() failure");
        return NULL;
    }
    dev->type = NET_DEVICE_TYPE_NULL;
    dev->mtu = DUMMY_MTU;
    dev->hlen = 0;
    dev->alen = 0;
    dev->ops = &dummy_ops;
    if (net_device_register(dev) == -1) {
        errorf("net_device_register() failure");
        return NULL;
    }
    debugf("initialized, dev=%s", dev->name);
    return dev;
}
