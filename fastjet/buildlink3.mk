# $NetBSD: buildlink3.mk,v 1.1 2012/09/12 17:25:41 jihbed Exp $

BUILDLINK_TREE+=	fastjet

.if !defined(FASTJET_BUILDLINK3_MK)
FASTJET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fastjet+=	fastjet>=3.0.1
BUILDLINK_PKGSRCDIR.fastjet?=	../../wip/fastjet
.endif	# FASTJET_BUILDLINK3_MK

BUILDLINK_TREE+=	-fastjet
