# $NetBSD: buildlink3.mk,v 1.1 2012/10/03 15:05:59 othyro Exp $

BUILDLINK_TREE+=	sfml

.if !defined(SFML_BUILDLINK3_MK)
SFML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sfml+=	sfml>=1.6
BUILDLINK_PKGSRCDIR.sfml?=	../../wip/sfml

.include "../../graphics/glu/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif	# SFML_BUILDLINK3_MK

BUILDLINK_TREE+=	-sfml
