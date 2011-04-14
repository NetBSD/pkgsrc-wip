# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/04/14 09:07:40 bartoszkuzma Exp $

BUILDLINK_TREE+=	libestr

.if !defined(LIBESTR_BUILDLINK3_MK)
LIBESTR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libestr+=	libestr>=0.1.0
BUILDLINK_ABI_DEPENDS.libestr+=	libestr>=0.1.0
BUILDLINK_PKGSRCDIR.libestr?=	../../wip/libestr

.endif # LIBESTR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libestr
