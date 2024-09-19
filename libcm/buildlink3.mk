# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libcm

.if !defined(LIBCM_BUILDLINK3_MK)
LIBCM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcm+=	libcm>=0.1.1
BUILDLINK_PKGSRCDIR.libcm?=	../../wip/libcm

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif # LIBCM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcm
