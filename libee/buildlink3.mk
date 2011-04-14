# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/04/14 09:06:55 bartoszkuzma Exp $

BUILDLINK_TREE+=	libee

.if !defined(LIBEE_BUILDLINK3_MK)
LIBEE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libee+=	libee>=0.3.0
BUILDLINK_ABI_DEPENDS.libee+=	libee>=0.3.0
BUILDLINK_PKGSRCDIR.libee?=	../../wip/libee

.endif # LIBEE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libee
