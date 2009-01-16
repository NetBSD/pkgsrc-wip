# $NetBSD: buildlink3.mk,v 1.2 2009/01/16 08:43:19 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LUCU_BUILDLINK3_MK:=	${LUCU_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	Lucu
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NLucu}
BUILDLINK_PACKAGES+=	Lucu
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Lucu

.if ${LUCU_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.Lucu+=	Lucu>=0.2
BUILDLINK_PKGSRCDIR.Lucu?=	../../wip/Lucu
.endif	# LUCU_BUILDLINK3_MK

.include "../../wip/HsOpenSSL/buildlink3.mk"
.include "../../wip/haskell-src/buildlink3.mk"
.include "../../wip/hs-dataenc/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../wip/hxt/buildlink3.mk"
.include "../../wip/stm/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
