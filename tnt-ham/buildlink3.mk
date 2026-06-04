# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/02 11:59:04 jihbed Exp $

BUILDLINK_TREE+=	tnt

.if !defined(TNT_BUILDLINK3_MK)
TNT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tnt+=	tnt>=3.0.12
BUILDLINK_PKGSRCDIR.tnt?=	../../wip/tnt
.endif	# TNT_BUILDLINK3_MK

BUILDLINK_TREE+=	-tnt
