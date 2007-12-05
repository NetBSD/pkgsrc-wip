# $NetBSD: buildlink3.mk,v 1.8 2007/12/05 06:29:49 netcap Exp $

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
BUILDLINK_PKGSRCDIR.ecore?=	../../wip/ecore
.endif	# ECORE_BUILDLINK3_MK

.include "../../wip/eet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
