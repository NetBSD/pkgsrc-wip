# $NetBSD: buildlink3.mk,v 1.6 2014/05/20 21:23:20 szptvlfn Exp $

BUILDLINK_TREE+=	hs-yaml

.if !defined(HS_YAML_BUILDLINK3_MK)
HS_YAML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-yaml+=	hs-yaml>=0.8.5
BUILDLINK_PKGSRCDIR.hs-yaml?=	../../wip/hs-yaml

.include "../../wip/hs-aeson/buildlink3.mk"
.include "../../wip/hs-attoparsec/buildlink3.mk"
.include "../../wip/hs-conduit/buildlink3.mk"
.include "../../devel/hs-data-default/buildlink3.mk"
.include "../../wip/hs-resourcet/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_YAML_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-yaml
