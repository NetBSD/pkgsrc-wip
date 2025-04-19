# $NetBSD$

BUILDLINK_TREE+=	efl

.if !defined(EFL_BUILDLINK3_MK)
EFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efl+=	efl>=1.28.0
BUILDLINK_PKGSRCDIR.efl?=	../../wip/efl

LUA_VERSIONS_ACCEPTED=	52 51

pkgbase := efl
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.efl:Mg-mainloop}
.include "../../devel/libuv/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.efl:Mpulseaudio}
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.efl:Mclang}
.include "../../parallel/openmp/buildlink3.mk"
.endif

.if ${X11_TYPE} == "modular"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.if ${OPSYS} == "Linux"
.include "../../sysutils/libudev/buildlink3.mk"
.include "../../wip/libinput/buildlink3.mk"
.endif
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"

.endif	# EFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-efl
