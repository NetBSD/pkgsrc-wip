# $NetBSD: buildlink3.mk,v 1.3 2009/01/16 08:39:06 phonohawk Exp $

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
BUILDLINK_API_DEPENDS.hxt+=	hxt>=8.2.0
BUILDLINK_PKGSRCDIR.hxt?=	../../wip/hxt
.endif	# HXT_BUILDLINK3_MK

.include "../../wip/HUnit/buildlink3.mk"
.include "../../wip/hs-curl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-parallel/buildlink3.mk"
.include "../../wip/parsec/buildlink3.mk"
.include "../../wip/tagsoup/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
