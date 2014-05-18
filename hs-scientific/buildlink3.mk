# $NetBSD: buildlink3.mk,v 1.2 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-scientific

.if !defined(HS_SCIENTIFIC_BUILDLINK3_MK)
HS_SCIENTIFIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-scientific+=	hs-scientific>=0.2.0
BUILDLINK_PKGSRCDIR.hs-scientific?=	../../wip/hs-scientific

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.endif	# HS_SCIENTIFIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-scientific
