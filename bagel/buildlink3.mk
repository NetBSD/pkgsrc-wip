# $NetBSD: buildlink3.mk,v 1.1 2011/12/28 20:20:32 jihbed Exp $

BUILDLINK_TREE+=	bagel

.if !defined(BAGEL_BUILDLINK3_MK)
BAGEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bagel+=	bagel>=2.0.0
BUILDLINK_PKGSRCDIR.bagel?=	../../wip/bagel
.endif	# BAGEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-bagel
