# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libuxre

.if !defined(LIBUXRE_BUILDLINK3_MK)
LIBUXRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libuxre+=	libuxre>=060122
BUILDLINK_PKGSRCDIR.libuxre?=	../../wip/libuxre
BUILDLINK_INCDIRS.libuxre+=	include/uxre
.endif # LIBUXRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libuxre
