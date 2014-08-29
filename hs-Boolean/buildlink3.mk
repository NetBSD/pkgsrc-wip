# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:09:59 szptvlfn Exp $

BUILDLINK_TREE+=	hs-Boolean

.if !defined(HS_BOOLEAN_BUILDLINK3_MK)
HS_BOOLEAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Boolean+=	hs-Boolean>=0.2
BUILDLINK_ABI_DEPENDS.hs-Boolean+=	hs-Boolean>=0.2
BUILDLINK_PKGSRCDIR.hs-Boolean?=	../../wip/hs-Boolean
.endif	# HS_BOOLEAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Boolean
