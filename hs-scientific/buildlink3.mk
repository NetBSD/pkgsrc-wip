# $NetBSD: buildlink3.mk,v 1.1 2014/01/15 23:22:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-scientific

.if !defined(HS_SCIENTIFIC_BUILDLINK3_MK)
HS_SCIENTIFIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-scientific+=	hs-scientific>=0.2.0
BUILDLINK_PKGSRCDIR.hs-scientific?=	../../wip/hs-scientific

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_SCIENTIFIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-scientific
