# $NetBSD: buildlink3.mk,v 1.6 2014/05/31 23:44:19 wiz Exp $

BUILDLINK_TREE+=	compat32_giflib

.if !defined(COMPAT32_GIFLIB_BUILDLINK3_MK)
COMPAT32_GIFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_giflib+=	compat32_giflib>=5.1.0
BUILDLINK_PKGSRCDIR.compat32_giflib?=	../../wip/compat32_giflib
BUILDLINK_LIBDIRS.compat32_giflib=	emul/netbsd32/lib
BUILDLINK_INCDIRS.compat32_giflib=	emul/netbsd32/include

.endif	# COMPAT32_GIFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_giflib
