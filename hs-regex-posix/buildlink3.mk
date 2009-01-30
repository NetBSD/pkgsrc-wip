# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/30 14:54:03 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_REGEX_POSIX_BUILDLINK3_MK:=	${HS_REGEX_POSIX_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-regex-posix
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-regex-posix}
BUILDLINK_PACKAGES+=	hs-regex-posix
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-regex-posix

.if ${HS_REGEX_POSIX_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-regex-posix?=	build
BUILDLINK_API_DEPENDS.hs-regex-posix+=	hs-regex-posix>=0.93.2
BUILDLINK_PKGSRCDIR.hs-regex-posix?=	../../wip/hs-regex-posix
.endif	# HS_REGEX_POSIX_BUILDLINK3_MK

.include "../../wip/hs-regex-base/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
