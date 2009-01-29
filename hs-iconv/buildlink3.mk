# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/01/29 10:14:21 phonohawk Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_ICONV_BUILDLINK3_MK:=	${HS_ICONV_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-iconv
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-iconv}
BUILDLINK_PACKAGES+=	hs-iconv
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-iconv

.if ${HS_ICONV_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-iconv?=	build
BUILDLINK_API_DEPENDS.hs-iconv+=	hs-iconv>=0.4.0.2
BUILDLINK_PKGSRCDIR.hs-iconv?=	../../wip/hs-iconv
.endif	# HS_ICONV_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
