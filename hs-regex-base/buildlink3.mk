# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/30 14:38:32 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
REGEX_BASE_BUILDLINK3_MK:=	${REGEX_BASE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	regex-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nregex-base}
BUILDLINK_PACKAGES+=	regex-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}regex-base

.if ${REGEX_BASE_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.regex-base?=	build
BUILDLINK_API_DEPENDS.regex-base+=	regex-base>=0.93.1
BUILDLINK_PKGSRCDIR.regex-base?=	../../wip/hs-regex-base
.endif	# REGEX_BASE_BUILDLINK3_MK

.include "../../wip/hs-mtl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
