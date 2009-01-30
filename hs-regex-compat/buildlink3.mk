# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/30 15:13:12 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_REGEX_COMPAT_BUILDLINK3_MK:=	${HS_REGEX_COMPAT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-regex-compat
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-regex-compat}
BUILDLINK_PACKAGES+=	hs-regex-compat
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-regex-compat

.if ${HS_REGEX_COMPAT_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-regex-compat?=	build
BUILDLINK_API_DEPENDS.hs-regex-compat+=	hs-regex-compat>=0.92
BUILDLINK_PKGSRCDIR.hs-regex-compat?=	../../wip/hs-regex-compat
.endif	# HS_REGEX_COMPAT_BUILDLINK3_MK

.include "../../wip/hs-regex-base/buildlink3.mk"
.include "../../wip/hs-regex-posix/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
