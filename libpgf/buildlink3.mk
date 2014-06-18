# $NetBSD: buildlink3.mk,v 1.1 2014/06/18 14:08:01 nros Exp $
#

BUILDLINK_TREE+=	libpgf

.if !defined(LIBPGF_BUILDLINK3_MK)
LIBPGF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpgf+=	libpgf>=6.14.12
BUILDLINK_PKGSRCDIR.libpgf?=	../../wip/libpgf
.endif	# LIBPGF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpgf
