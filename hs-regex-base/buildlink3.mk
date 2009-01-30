# $NetBSD: buildlink3.mk,v 1.2 2009/01/30 14:47:25 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_REGEX_BASE_BUILDLINK3_MK:=	${HS_REGEX_BASE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-regex-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-regex-base}
BUILDLINK_PACKAGES+=	hs-regex-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-regex-base

.if ${HS_REGEX_BASE_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-regex-base?=	build
BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.93.1
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../wip/hs-regex-base
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

.include "../../wip/hs-mtl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
