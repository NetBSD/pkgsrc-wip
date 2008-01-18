# $NetBSD: buildlink3.mk,v 1.13 2008/01/18 04:30:13 tnn2 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EVAS_BUILDLINK3_MK:=	${EVAS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	evas
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nevas}
BUILDLINK_PACKAGES+=	evas
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}evas

.if ${EVAS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.evas+=	evas>=0.9.9.041
BUILDLINK_ABI_DEPENDS.evas?=	evas>=0.9.9.041nb4
BUILDLINK_PKGSRCDIR.evas?=	../../wip/evas
.endif	# EVAS_BUILDLINK3_MK

.include "../../wip/eet/buildlink3.mk"
.include "../../wip/libxcb/buildlink3.mk"
.include "../../wip/xcb-proto/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../databases/edb/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/glitz/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
