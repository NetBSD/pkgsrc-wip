# $NetBSD: buildlink3.mk,v 1.1 2009/01/30 15:54:26 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DARCS_BUILDLINK3_MK:=	${DARCS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	darcs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndarcs}
BUILDLINK_PACKAGES+=	darcs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}darcs

.if ${DARCS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.darcs+=	darcs>=2.2.0
BUILDLINK_PKGSRCDIR.darcs?=	../../wip/darcs
.endif	# DARCS_BUILDLINK3_MK

.include "../../wip/hs-html/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-regex-compat/buildlink3.mk"
.include "../../wip/parsec/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
