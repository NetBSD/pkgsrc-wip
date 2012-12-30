# $NetBSD: buildlink3.mk,v 1.19 2012/12/30 19:28:50 roelants Exp $

BUILDLINK_TREE+=	evas

.if !defined(EVAS_BUILDLINK3_MK)
EVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evas+=	evas>=1.7.0
BUILDLINK_PKGSRCDIR.evas?=	../../wip/evas

.include "../../wip/eet/buildlink3.mk"
.include "../../wip/eina/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # EVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-evas
