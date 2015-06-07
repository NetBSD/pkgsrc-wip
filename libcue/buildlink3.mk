# $NetBSD: buildlink3.mk,v 1.1 2015/06/07 14:49:04 ishit Exp $

BUILDLINK_TREE+=	libcue

.if !defined(LIBCUE_BUILDLINK3_MK)
LIBCUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcue+=	libcue>=1.4.0
BUILDLINK_ABI_DEPENDS.libcue+=	libcue>=1.4.0
#BUILDLINK_PKGSRCDIR.libcue?=	../../audio/libcue
BUILDLINK_PKGSRCDIR.libcue?=	../../wip/libcue

.endif # LIBCUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcue
