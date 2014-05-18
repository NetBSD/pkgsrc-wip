# $NetBSD: buildlink3.mk,v 1.3 2014/05/18 21:33:30 szptvlfn Exp $

BUILDLINK_TREE+=	hs-wai

.if !defined(HS_WAI_BUILDLINK3_MK)
HS_WAI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai+=	hs-wai>=1.4.1
BUILDLINK_PKGSRCDIR.hs-wai?=	../../wip/hs-wai

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-conduit/buildlink3.mk"
.include "../../wip/hs-http-types/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../wip/hs-vault/buildlink3.mk"
.endif	# HS_WAI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai
