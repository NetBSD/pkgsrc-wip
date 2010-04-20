# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/04/20 20:12:00 jihbed Exp $

BUILDLINK_TREE+=	lasem

.if !defined(LASEM_BUILDLINK3_MK)
LASEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lasem+=	lasem>=0.2.0
BUILDLINK_PKGSRCDIR.lasem?=	../../wip/lasem

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.endif	# LASEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-lasem
