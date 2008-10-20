# $NetBSD: buildlink3.mk,v 1.11 2008/10/20 00:09:22 minskim Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ECORE_BUILDLINK3_MK:=	${ECORE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	ecore
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Necore}
BUILDLINK_PACKAGES+=	ecore
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}ecore

.if ${ECORE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.ecore+=	ecore>=0.9.9.041
BUILDLINK_ABI_DEPENDS.ecore?=	ecore>=0.9.9.042nb1
BUILDLINK_PKGSRCDIR.ecore?=	../../wip/ecore
.endif	# ECORE_BUILDLINK3_MK

.include "../../devel/eet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
