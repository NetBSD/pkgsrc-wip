# $NetBSD: buildlink3.mk,v,v 0.2 2018/09/06 16:15:10 andyb Exp $

BUILDLINK_TREE+=	efl121

.if !defined(EFL121_BUILDLINK3_MK)
EFL121_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efl121+=	efl121>=1.2.1
BUILDLINK_ABI_DEPENDS.efl121?=	efl121>=1.2.1nb10
BUILDLINK_PKGSRCDIR.efl121?=	../../wip/efl121

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/poppler-cpp/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../print/libspectre/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libraw/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/bullet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.endif # EFL121_BUILDLINK3_MK

BUILDLINK_TREE+=	-efl121
