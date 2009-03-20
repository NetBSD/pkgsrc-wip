# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	hscolour

.if !defined(HSCOLOUR_BUILDLINK3_MK)
HSCOLOUR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hscolour+=	hscolour>=1.11
BUILDLINK_PKGSRCDIR.hscolour?=	../../wip/hscolour
.endif # HSCOLOUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-hscolour
