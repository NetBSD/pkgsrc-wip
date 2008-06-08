# $NetBSD: buildlink3.mk,v 1.3 2008/06/08 17:47:45 zul_ Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
HS_X11_EXTRAS_BUILDLINK3_MK:=	${HS_X11_EXTRAS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hs-x11-extras
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhs-x11-extras}
BUILDLINK_PACKAGES+=	hs-x11-extras
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hs-x11-extras

.if ${HS_X11_EXTRAS_BUILDLINK3_MK} == "+"
BUILDLINK_DEPMETHOD.hs-x11-extras?=	build
BUILDLINK_API_DEPENDS.hs-x11-extras+=	hs-x11-extras>=0.4
BUILDLINK_PKGSRCDIR.hs-x11-extras?=	../../wip/hs-x11-extras
.endif	# HS_X11_EXTRAS_BUILDLINK3_MK

.include "../../wip/hs-x11/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
