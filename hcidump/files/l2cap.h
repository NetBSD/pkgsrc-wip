/*	$NetBSD: l2cap.h,v 1.2 2005/11/14 23:43:28 plunky Exp $	*/
/*-
 * Copyright (c) Maksim Yevmenkin <m_evmenkin@yahoo.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Id: l2cap.h,v 1.2 2005/11/14 23:43:28 plunky Exp $
 * $FreeBSD: src/sys/netgraph/bluetooth/include/l2cap.h,v 1.4 2005/08/31 18:13:23 emax Exp $
 */

/*
 * This file contains everything that application needs to know about
 * Link Layer Control and Adaptation Protocol (L2CAP). All information 
 * was obtained from Bluetooth Specification Book v1.1.
 *
 * This file can be included by both kernel and userland applications.
 */

#ifndef _NETBT_L2CAP_H_
#define _NETBT_L2CAP_H_

/**************************************************************************
 **************************************************************************
 **                   Common defines and types (L2CAP)
 **************************************************************************
 **************************************************************************/

/*
 * Channel IDs are assigned relative to the instance of L2CAP node, i.e.
 * relative to the unit. So the total number of channels that unit can have
 * open at the same time is 0xffff - 0x0040 = 0xffbf (65471). This number
 * does not depend on number of connections.
 */

#define L2CAP_NULL_CID			0x0000	/* DO NOT USE THIS CID */
#define L2CAP_SIGNAL_CID		0x0001	/* signaling channel ID */
#define L2CAP_CLT_CID			0x0002	/* connectionless channel ID */
	/* 0x0003 - 0x003f Reserved */
#define L2CAP_FIRST_CID			0x0040	/* dynamically alloc. (start) */
#define L2CAP_LAST_CID			0xffff	/* dynamically alloc. (end) */

/* L2CAP MTU */
#define L2CAP_MTU_MINIMUM		48
#define L2CAP_MTU_DEFAULT		672
#define L2CAP_MTU_MAXIMUM		0xffff

/* L2CAP flush and link timeouts */
#define L2CAP_FLUSH_TIMO_DEFAULT	0xffff /* always retransmit */
#define L2CAP_LINK_TIMO_DEFAULT		0xffff

/* L2CAP Command Reject reasons */
#define L2CAP_REJ_NOT_UNDERSTOOD	0x0000
#define L2CAP_REJ_MTU_EXCEEDED		0x0001
#define L2CAP_REJ_INVALID_CID		0x0002
/* 0x0003 - 0xffff - reserved for future use */

/* Protocol/Service Multioplexor (PSM) values */
#define L2CAP_PSM_ANY			0x0000	/* Any/Invalid PSM */
#define L2CAP_PSM_SDP			0x0001	/* Service Discovery Protocol */
#define L2CAP_PSM_RFCOMM		0x0003	/* RFCOMM protocol */
#define L2CAP_PSM_TCP			0x0005	/* Telephony Control Protocol */
/* 0x0006 - 0x1000 - reserved for future use */

/* L2CAP Connection response command result codes */
#define L2CAP_SUCCESS			0x0000
#define L2CAP_PENDING			0x0001
#define L2CAP_PSM_NOT_SUPPORTED		0x0002
#define L2CAP_SEQUIRY_BLOCK		0x0003
#define L2CAP_NO_RESOURCES		0x0004
#define L2CAP_TIMEOUT			0xeeee
#define L2CAP_UNKNOWN			0xffff
/* 0x0005 - 0xffff - reserved for future use */

/* L2CAP Connection response status codes */
#define L2CAP_NO_INFO			0x0000
#define L2CAP_AUTH_PENDING		0x0001
#define L2CAP_AUTZ_PENDING		0x0002
/* 0x0003 - 0xffff - reserved for future use */

/* L2CAP Configuration response result codes */
#define L2CAP_UNACCEPTABLE_PARAMS	0x0001
#define L2CAP_REJECT			0x0002
#define L2CAP_UNKNOWN_OPTION		0x0003
/* 0x0003 - 0xffff - reserved for future use */

/* L2CAP Configuration options */
#define L2CAP_OPT_CFLAG_BIT		0x0001
#define L2CAP_OPT_CFLAG(flags)	((flags) & L2CAP_OPT_CFLAG_BIT)
#define L2CAP_OPT_HINT_BIT		0x80
#define L2CAP_OPT_HINT(type)		((type) & L2CAP_OPT_HINT_BIT)
#define L2CAP_OPT_HINT_MASK		0x7f
#define L2CAP_OPT_MTU			0x01
#define L2CAP_OPT_MTU_SIZE		sizeof(u_int16_t)
#define L2CAP_OPT_FLUSH_TIMO		0x02
#define L2CAP_OPT_FLUSH_TIMO_SIZE	sizeof(u_int16_t)
#define L2CAP_OPT_QOS			0x03
#define L2CAP_OPT_QOS_SIZE		sizeof(l2cap_flow_t)
/* 0x4 - 0xff - reserved for future use */

/* L2CAP Information request type codes */
#define L2CAP_CONNLESS_MTU		0x0001
/* 0x0002 - 0xffff - reserved for future use */

/* L2CAP Information response codes */
#define L2CAP_NOT_SUPPORTED		0x0001
/* 0x0002 - 0xffff - reserved for future use */

/* L2CAP flow control */
typedef struct {
	u_int8_t	flags;             /* reserved for future use */
	u_int8_t	service_type;      /* service type */
	u_int32_t	token_rate;        /* bytes per second */
	u_int32_t	token_bucket_size; /* bytes */
	u_int32_t	peak_bandwidth;    /* bytes per second */
	u_int32_t	latency;           /* microseconds */
	u_int32_t	delay_variation;   /* microseconds */
} __attribute__ ((packed)) l2cap_flow_t;
typedef l2cap_flow_t *	l2cap_flow_p;

/**************************************************************************
 **************************************************************************
 **                 Link level defines, headers and types
 **************************************************************************
 **************************************************************************/

/* L2CAP header */
typedef struct {
	u_int16_t	length;	/* payload size */
	u_int16_t	dcid;	/* destination channel ID */
} __attribute__ ((packed)) l2cap_hdr_t;

/* L2CAP ConnectionLess Traffic (CLT) (if destination cid == 0x2) */
typedef struct {
	u_int16_t	psm; /* Protocol/Service Multiplexor */
} __attribute__ ((packed)) l2cap_clt_hdr_t;

#define L2CAP_CLT_MTU_MAXIMUM \
	(L2CAP_MTU_MAXIMUM - sizeof(l2cap_clt_hdr_t))

/* L2CAP command header */
typedef struct {
	u_int8_t	code;   /* command OpCode */
	u_int8_t	ident;  /* identifier to match request and response */
	u_int16_t	length; /* command parameters length */
} __attribute__ ((packed)) l2cap_cmd_hdr_t;

/* L2CAP Command Reject */
#define L2CAP_CMD_REJ			0x01
typedef struct {
	u_int16_t	reason; /* reason to reject command */
/*	u_int8_t	data[]; -- optional data (depends on reason) */
} __attribute__ ((packed)) l2cap_cmd_rej_cp;

/* CommandReject data */
typedef union {
 	/* L2CAP_REJ_MTU_EXCEEDED */
	struct {
		u_int16_t	mtu; /* actual signaling MTU */
	} __attribute__ ((packed)) mtu;
	/* L2CAP_REJ_INVALID_CID */
	struct {
		u_int16_t	scid; /* local CID */
		u_int16_t	dcid; /* remote CID */
	} __attribute__ ((packed)) cid;
} l2cap_cmd_rej_data_t;
typedef l2cap_cmd_rej_data_t * l2cap_cmd_rej_data_p;

/* L2CAP Connection Request */
#define L2CAP_CON_REQ			0x02
typedef struct {
	u_int16_t	psm;  /* Protocol/Service Multiplexor (PSM) */
	u_int16_t	scid; /* source channel ID */
} __attribute__ ((packed)) l2cap_con_req_cp;

/* L2CAP Connection Response */
#define L2CAP_CON_RSP			0x03
typedef struct {
	u_int16_t	dcid;   /* destination channel ID */
	u_int16_t	scid;   /* source channel ID */
	u_int16_t	result; /* 0x00 - success */
	u_int16_t	status; /* more info if result != 0x00 */
} __attribute__ ((packed)) l2cap_con_rsp_cp;

/* L2CAP Configuration Request */
#define L2CAP_CFG_REQ			0x04
typedef struct {
	u_int16_t	dcid;  /* destination channel ID */
	u_int16_t	flags; /* flags */
/*	u_int8_t	options[] --  options */
} __attribute__ ((packed)) l2cap_cfg_req_cp;

/* L2CAP Configuration Response */
#define L2CAP_CFG_RSP			0x05
typedef struct {
	u_int16_t	scid;   /* source channel ID */
	u_int16_t	flags;  /* flags */
	u_int16_t	result; /* 0x00 - success */
/*	u_int8_t	options[] -- options */
} __attribute__ ((packed)) l2cap_cfg_rsp_cp;

/* L2CAP configuration option */
typedef struct {
	u_int8_t	type;
	u_int8_t	length;
/*	u_int8_t	value[] -- option value (depends on type) */
} __attribute__ ((packed)) l2cap_cfg_opt_t;
typedef l2cap_cfg_opt_t * l2cap_cfg_opt_p;

/* L2CAP configuration option value */
typedef union {
	u_int16_t		mtu;		/* L2CAP_OPT_MTU */
	u_int16_t		flush_timo;	/* L2CAP_OPT_FLUSH_TIMO */
	l2cap_flow_t		flow;		/* L2CAP_OPT_QOS */
} l2cap_cfg_opt_val_t;
typedef l2cap_cfg_opt_val_t * l2cap_cfg_opt_val_p;

/* L2CAP Disconnect Request */
#define L2CAP_DISCON_REQ		0x06
typedef struct {
	u_int16_t	dcid; /* destination channel ID */
	u_int16_t	scid; /* source channel ID */
} __attribute__ ((packed)) l2cap_discon_req_cp;

/* L2CAP Disconnect Response */
#define L2CAP_DISCON_RSP		0x07
typedef l2cap_discon_req_cp	l2cap_discon_rsp_cp;

/* L2CAP Echo Request */
#define L2CAP_ECHO_REQ			0x08
/* No command parameters, only optional data */

/* L2CAP Echo Response */
#define L2CAP_ECHO_RSP			0x09
#define L2CAP_MAX_ECHO_SIZE \
	(L2CAP_MTU_MAXIMUM - sizeof(l2cap_cmd_hdr_t))
/* No command parameters, only optional data */

/* L2CAP Information Request */
#define L2CAP_INFO_REQ			0x0a
typedef struct {
	u_int16_t	type; /* requested information type */
} __attribute__ ((packed)) l2cap_info_req_cp;

/* L2CAP Information Response */
#define L2CAP_INFO_RSP			0x0b
typedef struct {
	u_int16_t	type;   /* requested information type */
	u_int16_t	result; /* 0x00 - success */
/*	u_int8_t	info[]  -- info data (depends on type)
 *
 * L2CAP_CONNLESS_MTU - 2 bytes connectionless MTU
 */
} __attribute__ ((packed)) l2cap_info_rsp_cp;

typedef union {
 	/* L2CAP_CONNLESS_MTU */
	struct {
		u_int16_t	mtu;
	} __attribute__ ((packed)) mtu;
} l2cap_info_rsp_data_t;
typedef l2cap_info_rsp_data_t *	l2cap_info_rsp_data_p;

/**************************************************************************
 **************************************************************************
 **        	L2CAP Socket Definitions
 **************************************************************************
 **************************************************************************/

#define SO_L2CAP_PSM		1
#define SO_L2CAP_IMTU		2
#define SO_L2CAP_OMTU		3
#define SO_L2CAP_IFLOW		4
#define SO_L2CAP_OFLOW		5
#define SO_L2CAP_FLUSH		6

#endif /* _NETBT_L2CAP_H_ */

/**************************************************************************
 **************************************************************************
 **        Upper layer protocol interface. L2CA_xxx messages 
 **************************************************************************
 **************************************************************************/

/* L2CA data packet header */
typedef struct {
	u_int32_t	token;	/* token to use in L2CAP_L2CA_WRITE */
	u_int16_t	length;	/* length of the data */
	u_int16_t	lcid;	/* local channel ID */
} __attribute__ ((packed)) l2cap_l2ca_hdr_t;

/* L2CA_Connect */
#define NGM_L2CAP_L2CA_CON		0x80
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	psm;    /* Protocol/Service Multiplexor */
	bdaddr_t	bdaddr;	/* remote unit address */
} l2cap_l2ca_con_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	lcid;   /* local channel ID */
	u_int16_t	result; /* 0x00 - success */
	u_int16_t	status; /* if result != 0x00 */
} l2cap_l2ca_con_op;

/* L2CA_ConnectInd */
#define NGM_L2CAP_L2CA_CON_IND		0x81
/* L2CAP -> Upper */
typedef struct {
	bdaddr_t	bdaddr; /* remote unit address */
	u_int16_t	lcid;   /* local channel ID */
	u_int16_t	psm;    /* Procotol/Service Multiplexor */
	u_int8_t	ident;  /* indentifier */
	u_int8_t	unused; /* place holder */
} l2cap_l2ca_con_ind_ip;
/* No output parameters */

/* L2CA_ConnectRsp */
#define NGM_L2CAP_L2CA_CON_RSP		0x82
/* Upper -> L2CAP */
typedef struct {
	bdaddr_t	bdaddr; /* remote unit address */
	u_int8_t	ident;  /* "ident" from L2CAP_ConnectInd event */
	u_int8_t	unused; /* place holder */
	u_int16_t	lcid;   /* local channel ID */
	u_int16_t	result; /* 0x00 - success */ 
	u_int16_t	status; /* if response != 0x00 */ 
} l2cap_l2ca_con_rsp_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result; /* 0x00 - success */
} l2cap_l2ca_con_rsp_op;

/* L2CA_Config */
#define NGM_L2CAP_L2CA_CFG		0x83
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	lcid;        /* local channel ID */
	u_int16_t	imtu;        /* receiving MTU for the local channel */
	l2cap_flow_t	oflow;       /* out flow */
	u_int16_t	flush_timo;  /* flush timeout (msec) */
	u_int16_t	link_timo;   /* link timeout (msec) */
} l2cap_l2ca_cfg_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result;      /* 0x00 - success */
	u_int16_t	imtu;        /* sending MTU for the remote channel */
	l2cap_flow_t	oflow;       /* out flow */
	u_int16_t	flush_timo;  /* flush timeout (msec) */
} l2cap_l2ca_cfg_op;

/* L2CA_ConfigRsp */
#define NGM_L2CAP_L2CA_CFG_RSP		0x84
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	lcid;  /* local channel ID */
	u_int16_t	omtu;  /* sending MTU for the local channel */
	l2cap_flow_t	iflow; /* in FLOW */
} l2cap_l2ca_cfg_rsp_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result; /* 0x00 - sucsess */
} l2cap_l2ca_cfg_rsp_op;

/* L2CA_ConfigInd */
#define NGM_L2CAP_L2CA_CFG_IND		0x85
/* L2CAP -> Upper */
typedef struct {
	u_int16_t	lcid;        /* local channel ID */
	u_int16_t	omtu;        /* outgoing MTU for the local channel */
	l2cap_flow_t	iflow;       /* in flow */
	u_int16_t	flush_timo;  /* flush timeout (msec) */
} l2cap_l2ca_cfg_ind_ip;
/* No output parameters */

/* L2CA_QoSViolationInd */
#define NGM_L2CAP_L2CA_QOS_IND		0x86
/* L2CAP -> Upper */
typedef struct {
	bdaddr_t	bdaddr;	/* remote unit address */
} l2cap_l2ca_qos_ind_ip;
/* No output parameters */

/* L2CA_Disconnect */
#define NGM_L2CAP_L2CA_DISCON		0x87
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	lcid;  /* local channel ID */
} l2cap_l2ca_discon_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result; /* 0x00 - sucsess */
} l2cap_l2ca_discon_op;

/* L2CA_DisconnectInd */
#define NGM_L2CAP_L2CA_DISCON_IND	0x88
/* L2CAP -> Upper */
typedef l2cap_l2ca_discon_ip l2cap_l2ca_discon_ind_ip;
/* No output parameters */

/* L2CA_Write response */
#define NGM_L2CAP_L2CA_WRITE		0x89
/* No input parameters */

/* L2CAP -> Upper */
typedef struct {
	int		result;	/* result (0x00 - success) */
	u_int16_t	length;	/* amount of data written */
	u_int16_t	lcid;	/* local channel ID */
} l2cap_l2ca_write_op;

/* L2CA_GroupCreate */
#define NGM_L2CAP_L2CA_GRP_CREATE	0x8a
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	psm;   /* Protocol/Service Multiplexor */
} l2cap_l2ca_grp_create_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	lcid;  /* local group channel ID */
} l2cap_l2ca_grp_create_op;

/* L2CA_GroupClose */
#define NGM_L2CAP_L2CA_GRP_CLOSE	0x8b
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	lcid;  /* local group channel ID */
} l2cap_l2ca_grp_close_ip;

#if 0
/* L2CAP -> Upper */
 * typedef struct {
 * 	u_int16_t	result; /* 0x00 - success */
 * } l2cap_l2ca_grp_close_op;
#endif

/* L2CA_GroupAddMember */
#define NGM_L2CAP_L2CA_GRP_ADD_MEMBER	0x8c
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	lcid;   /* local group channel ID */
	bdaddr_t	bdaddr; /* remote unit address */
} l2cap_l2ca_grp_add_member_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result; /* 0x00 - success */
} l2cap_l2ca_grp_add_member_op;

/* L2CA_GroupRemoveMember */
#define NGM_L2CAP_L2CA_GRP_REM_MEMBER	0x8d
/* Upper -> L2CAP */
typedef l2cap_l2ca_grp_add_member_ip	l2cap_l2ca_grp_rem_member_ip;

/* L2CAP -> Upper */
#if 0
 * typedef l2cap_l2ca_grp_add_member_op	l2cap_l2ca_grp_rem_member_op;
#endif

/* L2CA_GroupMembeship */
#define NGM_L2CAP_L2CA_GRP_MEMBERSHIP	0x8e
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	lcid;  /* local group channel ID */
} l2cap_l2ca_grp_get_members_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result;   /* 0x00 - success */
	u_int16_t	nmembers; /* number of group members */
/*	bdaddr_t	members[] -- group memebers */
} l2cap_l2ca_grp_get_members_op;

/* L2CA_Ping */
#define NGM_L2CAP_L2CA_PING		0x8f
/* Upper -> L2CAP */
typedef struct {
	bdaddr_t	bdaddr;    /* remote unit address */
	u_int16_t	echo_size; /* size of echo data in bytes */
/*	u_int8_t	echo_data[] -- echo data */
} l2cap_l2ca_piip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result;    /* 0x00 - success */
	bdaddr_t	bdaddr;    /* remote unit address */
	u_int16_t	echo_size; /* size of echo data in bytes */
/*	u_int8_t	echo_data[] -- echo data */
} l2cap_l2ca_piop;

/* L2CA_GetInfo */
#define NGM_L2CAP_L2CA_GET_INFO		0x90
/* Upper -> L2CAP */
typedef struct {
	bdaddr_t	bdaddr;	   /* remote unit address */
	u_int16_t	info_type; /* info type */
} l2cap_l2ca_get_info_ip;

/* L2CAP -> Upper */
typedef struct {
	u_int16_t	result;    /* 0x00 - success */
	u_int16_t	info_size; /* size of info data in bytes */
/*	u_int8_t	info_data[] -- info data */
} l2cap_l2ca_get_info_op;

/* L2CA_EnableCLT/L2CA_DisableCLT */
#define NGM_L2CAP_L2CA_ENABLE_CLT	0x91
/* Upper -> L2CAP */
typedef struct {
	u_int16_t	psm;    /* Protocol/Service Multiplexor */
	u_int16_t	enable; /* 0x00 - disable */
} l2cap_l2ca_enable_clt_ip;

#if 0
/* L2CAP -> Upper */
 * typedef struct {
 * 	u_int16_t	result; /* 0x00 - success */
 * } l2cap_l2ca_enable_clt_op;
#endif
