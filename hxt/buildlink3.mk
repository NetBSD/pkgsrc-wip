# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/07/20 07:01:06 phonohawk Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HXT_BUILDLINK3_MK:=	${HXT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hxt
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhxt}
BUILDLINK_PACKAGES+=	hxt
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hxt

.if ${HXT_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hxt?=	build
BUILDLINK_API_DEPENDS.hxt+=	hxt>=8.1.0
BUILDLINK_PKGSRCDIR.hxt?=	../../wip/hxt
.endif	# HXT_BUILDLINK3_MK

.include "../../wip/hs-curl/buildlink3.mk"
.include "../../wip/tagsoup/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
