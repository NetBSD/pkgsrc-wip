# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/12 20:33:18 marc Exp $
#

.if !defined(LIBFWBUILDER_BUILDLINK2_MK)
LIBFWBUILDER_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			libfwbuilder
BUILDLINK_DEPENDS.libfwbuilder?=		libfwbuilder>=0.10.13
BUILDLINK_PKGSRCDIR.libfwbuilder?=		../../wip/libfwbuilder

EVAL_PREFIX+=	BUILDLINK_PREFIX.libfwbuilder=libfwbuilder
BUILDLINK_PREFIX.libfwbuilder_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libfwbuilder+=	include/fwbuilder/*.h
BUILDLINK_FILES.libfwbuilder+=	include/fwbuilder/*.hh
BUILDLINK_FILES.libfwbuilder+=	include/fwcompiler/*.hh
BUILDLINK_FILES.libfwbuilder+=	lib/libfwbuilder.*
BUILDLINK_FILES.libfwbuilder+=	lib/libfwcompiler.*

.include "../../devel/glib/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../net/ucd-snmp/buildlink2.mk"
.include "../../net/bind9/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"

BUILDLINK_TARGETS+=	libfwbuilder-buildlink

libfwbuilder-buildlink: _BUILDLINK_USE

.endif	# LIBFWBUILDER_BUILDLINK2_MK
