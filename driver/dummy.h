#ifndef NULL_H
#define NULL_H

#include "net.h"

#define DUMMY_MTU UINT16_MAX

extern struct net_device * dummy_init(void);

#endif
