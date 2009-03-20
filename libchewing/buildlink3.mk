# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libchewing

.if !defined(LIBCHEWING_BUILDLINK3_MK)
LIBCHEWING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchewing+=		libchewing>=0.3.2
BUILDLINK_ABI_DEPENDS.libchewing+=	libchewing>=0.3.2
BUILDLINK_PKGSRCDIR.libchewing?=	../../wip/libchewing
.endif # LIBCHEWING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchewing
