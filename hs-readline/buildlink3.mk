# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/22 05:56:11 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_READLINE_BUILDLINK3_MK:=	${HS_READLINE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-readline
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-readline}
BUILDLINK_PACKAGES+=	hs-readline
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-readline

.if ${HS_READLINE_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-readline?=	build
BUILDLINK_API_DEPENDS.hs-readline+=	hs-readline>=1.0.1.0
BUILDLINK_PKGSRCDIR.hs-readline?=	../../wip/hs-readline
.endif	# HS_READLINE_BUILDLINK3_MK

.include "../../devel/readline/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
