# $NetBSD: buildlink3.mk,v 1.13 2012/07/03 06:35:37 lokivit Exp $

BUILDLINK_TREE+=	e17

.if !defined(E17_BUILDLINK3_MK)
E17_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.e17+=	e17>=0.16.999.55225
BUILDLINK_ABI_DEPENDS.e17?=	e17>=0.16.999.55225
BUILDLINK_PKGSRCDIR.e17?=	../../wip/e17

.include "../../devel/ecore/buildlink3.mk"
.include "../../graphics/edje/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../graphics/evas-buffer/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.endif # E17_BUILDLINK3_MK

BUILDLINK_TREE+=	-e17
