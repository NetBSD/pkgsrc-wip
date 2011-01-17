# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/17 22:02:17 jihbed Exp $

BUILDLINK_TREE+=	ann

.if !defined(ANN_BUILDLINK3_MK)
ANN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ann+=	ann>=1.1.2
BUILDLINK_PKGSRCDIR.ann?=	../../wip/ann
.endif	# ANN_BUILDLINK3_MK

BUILDLINK_TREE+=	-ann
