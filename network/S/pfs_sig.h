/*
* Copyright (C) 2012-2014 www.56.com email: jingchun.zhang AT renren-inc.com; jczhang AT 126.com ; danezhang77 AT gmail.com
* 
* 56VFS may be copied only under the terms of the GNU General Public License V3
*/
#ifndef __PFS_SIG_SO_H
#define __PFS_SIG_SO_H
#include "list.h"
#include "global.h"
#include "pfs_init.h"
#include "pfs_task.h"
#include "c_api.h"
#include "common.h"
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <dirent.h>

#define SELF_ROLE ROLE_CS

enum SOCK_STAT {LOGOUT = 0, CONNECTED, LOGIN, HB_SEND, HB_RSP, IDLE, RECV_LAST, SEND_LAST};

typedef struct {
	list_head_t alist;
	list_head_t hlist;
	list_head_t cfglist;
	t_pfs_sync_list *pfs_sync_list;  /* init set, when recv sync_dir_rsp  reset it*/
	int fd;
	uint32_t hbtime;
	uint32_t ip;
	uint32_t cfgip;
	uint8_t role;  /*FCS, CS, TRACKER */
	uint8_t sock_stat;   /* SOCK_STAT */
	uint8_t server_stat; /* server stat*/
	uint8_t bk;
} pfs_cs_peer;

int find_ip_stat(uint32_t ip, pfs_cs_peer **dpeer);

typedef struct {
	int flag;   /*0: idle, 1: sync_dir , 2: no more task for sync*/
	time_t last;
	int total_sync_task;
	int total_synced_task;
} t_sync_para;

#endif
