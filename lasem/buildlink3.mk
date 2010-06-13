# $NetBSD: buildlink3.mk,v 1.2 2010/06/13 22:47:09 thomasklausner Exp $

BUILDLINK_TREE+=	lasem

.if !defined(LASEM_BUILDLINK3_MK)
LASEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lasem+=	lasem>=0.2.0
BUILDLINK_ABI_DEPENDS.lasem?=	lasem>=0.2.0nb1
BUILDLINK_PKGSRCDIR.lasem?=	../../wip/lasem

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# LASEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-lasem
