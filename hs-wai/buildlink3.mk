# $NetBSD: buildlink3.mk,v 1.1 2013/11/25 11:39:41 szptvlfn Exp $

BUILDLINK_TREE+=	hs-wai

.if !defined(HS_WAI_BUILDLINK3_MK)
HS_WAI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-wai+=	hs-wai>=1.4.1
BUILDLINK_PKGSRCDIR.hs-wai?=	../../wip/hs-wai

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-conduit/buildlink3.mk"
.include "../../wip/hs-http-types/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-vault/buildlink3.mk"
.endif	# HS_WAI_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-wai
