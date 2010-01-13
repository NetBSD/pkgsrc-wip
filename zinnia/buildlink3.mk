# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/01/13 11:12:45 obache Exp $

BUILDLINK_TREE+=	zinnia

.if !defined(ZINNIA_BUILDLINK3_MK)
ZINNIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.zinnia+=	zinnia>=0.05
BUILDLINK_PKGSRCDIR.zinnia?=	../../wip/zinnia
.endif	# ZINNIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-zinnia
