# $NetBSD$

BUILDLINK_TREE+=	opencascade

.if !defined(OPENCASCADE_BUILDLINK3_MK)
OPENCASCADE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.opencascade+=	opencascade>=7.0.0
BUILDLINK_PKGSRCDIR.opencascade?=	../../wip/opencascade-git

BUILDLINK_INCDIRS.opencascade+=		include/opencascade
CMAKE_ARGS+=				-DOCC_INCLUDE_DIR=${BUILDLINK_PREFIX.opencascade}/include/opencascade

pkgbase:=	opencascade

.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.opencascade:Mx11}
.  include "../../graphics/freeimage/buildlink3.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.opencascade:Mocct-draw}
.  include "../../lang/tcl/buildlink3.mk"
.  include "../../x11/tk/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.endif	# OPENCASCADE_BUILDLINK3_MK

BUILDLINK_TREE+=	-opencascade
