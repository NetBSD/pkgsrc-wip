# $NetBSD: buildlink2.mk,v 1.1 2003/07/18 05:12:55 xtraeme Exp $
#
# This Makefile fragment is included by packages that use GNUnet.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(GNUNET_BUILDLINK2_MK)
GNUNET_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			GNUnet
BUILDLINK_DEPENDS.GNUnet?=		GNUnet>=0.5.4a
BUILDLINK_PKGSRCDIR.GNUnet?=		../../wip/gnunet

EVAL_PREFIX+=	BUILDLINK_PREFIX.GNUnet=GNUnet
BUILDLINK_PREFIX.GNUnet_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.GNUnet+=	include/ltdl.h
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_blocks.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_database.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_database_directory.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_database_gdbm.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_decoding.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_delete.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_encoding.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_policy.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_protocol.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_search.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetafs_util.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetchat_protocol.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetcommon.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunettbench_protocol.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunettracekit_protocol.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunettransport_http.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunettransport_smtp.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunettransport_tcp.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunettransport_udp.*
BUILDLINK_FILES.GNUnet+=	lib/libgnunetutil.*
BUILDLINK_FILES.GNUnet+=	lib/libltdl.*

.include "../../security/openssl/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"

BUILDLINK_TARGETS+=	GNUnet-buildlink

GNUnet-buildlink: _BUILDLINK_USE

.endif	# GNUNET_BUILDLINK2_MK
