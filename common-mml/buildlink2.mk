# $NetBSD: buildlink2.mk,v 1.1.1.1 2005/02/25 20:22:07 daprice Exp $
#
# This Makefile fragment is included by packages that use common-mml.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(COMMON_MML_BUILDLINK2_MK)
COMMON_MML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			common-mml
BUILDLINK_DEPENDS.common-mml?=		common-mml>=1.2.14
BUILDLINK_PKGSRCDIR.common-mml?=	../../mbone/common-mml

EVAL_PREFIX+=	BUILDLINK_PREFIX.common-mml=common-mml
BUILDLINK_PREFIX.common-mml_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.common-mml+=	include/common-mml/acconfig.h
BUILDLINK_FILES.common-mml+=	include/common-mml/addrinfo.h
BUILDLINK_FILES.common-mml+=	include/common-mml/addrsize.h
BUILDLINK_FILES.common-mml+=	include/common-mml/asarray.h
BUILDLINK_FILES.common-mml+=	include/common-mml/base64.h
BUILDLINK_FILES.common-mml+=	include/common-mml/bittypes.h
BUILDLINK_FILES.common-mml+=	include/common-mml/btree.h
BUILDLINK_FILES.common-mml+=	include/common-mml/cdecl_ext.h
BUILDLINK_FILES.common-mml+=	include/common-mml/config_unix.h
BUILDLINK_FILES.common-mml+=	include/common-mml/config_win32.h
BUILDLINK_FILES.common-mml+=	include/common-mml/crypt_random.h
BUILDLINK_FILES.common-mml+=	include/common-mml/debug.h
BUILDLINK_FILES.common-mml+=	include/common-mml/drand48.h
BUILDLINK_FILES.common-mml+=	include/common-mml/gettimeofday.h
BUILDLINK_FILES.common-mml+=	include/common-mml/hmac.h
BUILDLINK_FILES.common-mml+=	include/common-mml/inet_ntop.h
BUILDLINK_FILES.common-mml+=	include/common-mml/inet_pton.h
BUILDLINK_FILES.common-mml+=	include/common-mml/mbus.h
BUILDLINK_FILES.common-mml+=	include/common-mml/mbus_addr.h
BUILDLINK_FILES.common-mml+=	include/common-mml/mbus_config.h
BUILDLINK_FILES.common-mml+=	include/common-mml/mbus_parser.h
BUILDLINK_FILES.common-mml+=	include/common-mml/md5.h
BUILDLINK_FILES.common-mml+=	include/common-mml/memory.h
BUILDLINK_FILES.common-mml+=	include/common-mml/net_udp.h
BUILDLINK_FILES.common-mml+=	include/common-mml/ntp.h
BUILDLINK_FILES.common-mml+=	include/common-mml/qfDES.h
BUILDLINK_FILES.common-mml+=	include/common-mml/rijndael-alg-fst.h
BUILDLINK_FILES.common-mml+=	include/common-mml/rijndael-api-fst.h
BUILDLINK_FILES.common-mml+=	include/common-mml/rtp.h
BUILDLINK_FILES.common-mml+=	include/common-mml/sockstorage.h
BUILDLINK_FILES.common-mml+=	include/common-mml/uclconf.h
BUILDLINK_FILES.common-mml+=	include/common-mml/util.h
BUILDLINK_FILES.common-mml+=	include/common-mml/version.h
BUILDLINK_FILES.common-mml+=	include/common-mml/vsnprintf.h
BUILDLINK_FILES.common-mml+=	lib/libuclmmbase.*

BUILDLINK_TARGETS+=	common-mml-buildlink

common-mml-buildlink: _BUILDLINK_USE

.endif	# COMMON_MML_BUILDLINK2_MK
