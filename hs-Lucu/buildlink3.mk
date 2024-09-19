# $NetBSD: buildlink3.mk,v 1.15 2014/08/29 14:10:01 szptvlfn Exp $

BUILDLINK_TREE+=	hs-Lucu

.if !defined(HS_LUCU_BUILDLINK3_MK)
HS_LUCU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-Lucu+=	hs-Lucu>=0.7.0
BUILDLINK_ABI_DEPENDS.hs-Lucu+=	hs-Lucu>=0.7.0.3nb2
BUILDLINK_PKGSRCDIR.hs-Lucu?=	../../wip/hs-Lucu

.include "../../wip/hs-HsOpenSSL/buildlink3.mk"
.include "../../devel/hs-base-unicode-symbols/buildlink3.mk"
.include "../../converters/hs-base64-bytestring/buildlink3.mk"
.include "../../wip/hs-haskell-src/buildlink3.mk"
.include "../../textproc/hs-hxt/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-stm/buildlink3.mk"
.include "../../wip/hs-time-http/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_LUCU_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-Lucu
