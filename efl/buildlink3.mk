# $NetBSD$

BUILDLINK_TREE+=	efl

.if !defined(EFL_BUILDLINK3_MK)
EFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efl+=	efl>=1.25.0
BUILDLINK_PKGSRCDIR.efl?=	../../wip/efl

pkgbase := efl
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_OPTIONS.efl:Mg-mainloop)
.include "../../devel/libuv/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS.efl:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.if ${X11_TYPE} == "modular"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif

.include "../../audio/libsndfile/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../inputmethod/scim/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif	# EFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-efl
