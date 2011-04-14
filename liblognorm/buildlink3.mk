# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/04/14 09:09:46 bartoszkuzma Exp $

BUILDLINK_TREE+=	liblognorm

.if !defined(LIBLOGNORM_BUILDLINK3_MK)
LIBLOGNORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liblognorm+=	liblognorm>=0.3.0
BUILDLINK_ABI_DEPENDS.liblognorm+=	liblognorm>=0.3.0
BUILDLINK_PKGSRCDIR.liblognorm=		../../wip/liblognorm

.endif # LIBLOGNORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-liblognorm
