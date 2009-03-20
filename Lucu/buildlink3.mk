# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	Lucu

.if !defined(LUCU_BUILDLINK3_MK)
LUCU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.Lucu+=	Lucu>=0.2
BUILDLINK_PKGSRCDIR.Lucu?=	../../wip/Lucu

.include "../../wip/HsOpenSSL/buildlink3.mk"
.include "../../wip/haskell-src/buildlink3.mk"
.include "../../wip/hs-dataenc/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../wip/hxt/buildlink3.mk"
.include "../../wip/stm/buildlink3.mk"
.endif # LUCU_BUILDLINK3_MK

BUILDLINK_TREE+=	-Lucu
