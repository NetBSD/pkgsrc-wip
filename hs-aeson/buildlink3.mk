# $NetBSD: buildlink3.mk,v 1.2 2014/01/25 14:09:55 szptvlfn Exp $

BUILDLINK_TREE+=	hs-aeson

.if !defined(HS_AESON_BUILDLINK3_MK)
HS_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-aeson+=	hs-aeson>=0.7.0
BUILDLINK_PKGSRCDIR.hs-aeson?=	../../wip/hs-aeson

.include "../../wip/hs-attoparsec/buildlink3.mk"
.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-scientific/buildlink3.mk"
.include "../../wip/hs-syb/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-aeson
