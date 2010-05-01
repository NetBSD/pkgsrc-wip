# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/01 23:05:33 thomasklausner Exp $

BUILDLINK_TREE+=	talloc

.if !defined(TALLOC_BUILDLINK3_MK)
TALLOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.talloc+=	talloc>=2.0.1
BUILDLINK_PKGSRCDIR.talloc?=	../../wip/talloc
.endif	# TALLOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-talloc
