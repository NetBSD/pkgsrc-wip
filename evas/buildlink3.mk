# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/09/16 15:03:12 airhead Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EVAS_BUILDLINK3_MK:=	${EVAS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	evas
.endif

BUILDLINK_PACKAGES+=	evas

.if !empty(EVAS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.evas+=	evas>=1.0.0nb1
BUILDLINK_PKGSRCDIR.evas?=	../../wip/evas.import
.endif	# EVAS_BUILDLINK3_MK

.include "../../devel/libtool/buildlink3.mk"
.include "../../databases/edb/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/Mesa/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
