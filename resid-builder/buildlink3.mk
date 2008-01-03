# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/01/03 02:01:06 hoka_adam Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
RESID_BUILDER_BUILDLINK3_MK:=	${RESID_BUILDER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	resid-builder
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nresid-builder}
BUILDLINK_PACKAGES+=	resid-builder
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}resid-builder

.if ${RESID_BUILDER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.resid-builder+=	resid-builder>=20060528
BUILDLINK_PKGSRCDIR.resid-builder?=	../../wip/resid-builder
.endif	# RESID_BUILDER_BUILDLINK3_MK

.include "../../wip/libsidplay2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
