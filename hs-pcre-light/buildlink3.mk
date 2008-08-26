# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/08/26 05:40:20 phonohawk Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_PCRE_LIGHT_BUILDLINK3_MK:=	${HS_PCRE_LIGHT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-pcre-light
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-pcre-light}
BUILDLINK_PACKAGES+=	hs-pcre-light
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-pcre-light

.if ${HS_PCRE_LIGHT_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-pcre-light?=	build
BUILDLINK_API_DEPENDS.hs-pcre-light+=	hs-pcre-light>=0.3.1
BUILDLINK_PKGSRCDIR.hs-pcre-light?=	../../wip/hs-pcre-light
.endif	# HS_PCRE_LIGHT_BUILDLINK3_MK

.include "../../devel/pcre/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
