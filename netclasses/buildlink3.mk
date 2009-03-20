# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	netclasses

.if !defined(NETCLASSES_BUILDLINK3_MK)
NETCLASSES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netclasses+=	netclasses>=1.06
BUILDLINK_PKGSRCDIR.netclasses?=	../../wip/netclasses
.endif # NETCLASSES_BUILDLINK3_MK

BUILDLINK_TREE+=	-netclasses
