# $NetBSD$

BUILDLINK_TREE+=	occt

.if !defined(OCCT_BUILDLINK3_MK)
OCCT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.occt+=	occt>=7.7.0
BUILDLINK_ABI_DEPENDS.occt+=	occt>=7.7.0nb2
BUILDLINK_PKGSRCDIR.occt?=	../../wip/occt

BUILDLINK_INCDIRS.occt+=	include/opencascade
CMAKE_CONFIGURE_ARGS+=			-DOCC_INCLUDE_DIR=${BUILDLINK_PREFIX.occt}/include/opencascade

pkgbase := occt
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.occt:Mx11}
.  include "../../graphics/freeimage/buildlink3.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../x11/libX11/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.occt:Mocct-draw}
.  include "../../lang/tcl/buildlink3.mk"
.  include "../../x11/tk/buildlink3.mk"
.endif

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.endif	# OCCT_BUILDLINK3_MK

BUILDLINK_TREE+=	-occt
