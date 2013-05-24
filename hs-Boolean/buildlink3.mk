# $NetBSD: buildlink3.mk,v 1.1 2013/05/24 22:01:52 szptvlfn Exp $

BUILDLINK_TREE+=	hs-Boolean

.if !defined(HS_BOOLEAN_BUILDLINK3_MK)
HS_BOOLEAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Boolean+=	hs-Boolean>=0.2
BUILDLINK_PKGSRCDIR.hs-Boolean?=	../../wip/hs-Boolean
.endif	# HS_BOOLEAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Boolean
