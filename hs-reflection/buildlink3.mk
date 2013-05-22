# $NetBSD: buildlink3.mk,v 1.1 2013/05/22 19:12:43 szptvlfn Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=1.3.2
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../wip/hs-reflection

.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
