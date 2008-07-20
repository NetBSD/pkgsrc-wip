# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/07/20 07:49:50 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LUCU_BUILDLINK3_MK:=	${LUCU_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	Lucu
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NLucu}
BUILDLINK_PACKAGES+=	Lucu
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}Lucu

.if ${LUCU_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.Lucu?=	build
BUILDLINK_API_DEPENDS.Lucu+=	Lucu>=0.1
BUILDLINK_PKGSRCDIR.Lucu?=	../../wip/Lucu
.endif	# LUCU_BUILDLINK3_MK

.include "../../wip/HsOpenSSL/buildlink3.mk"
.include "../../wip/hs-dataenc/buildlink3.mk"
.include "../../wip/hs-zlib/buildlink3.mk"
.include "../../wip/hxt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
