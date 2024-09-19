# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	vale

.if !defined(VALE_BUILDLINK3_MK)
VALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vale+=	vale>=0.0.2
BUILDLINK_PKGSRCDIR.vale?=	../../wip/vale-current
.endif # VALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-vale
