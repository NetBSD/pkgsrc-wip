# $NetBSD: buildlink3.mk,v 1.2 2011/04/25 23:03:16 jihbed Exp $

BUILDLINK_TREE+=	minuit2

.if !defined(MINUIT2_BUILDLINK3_MK)
MINUIT2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.minuit2+=	minuit2>=5.28.00
BUILDLINK_PKGSRCDIR.minuit2?=	../../wip/minuit2
.endif	# MINUIT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-minuit2
