# $NetBSD: buildlink3.mk,v 1.3 2013/05/07 03:00:49 othyro Exp $

BUILDLINK_TREE+=	SDL2

.if !defined(SDL2_BUILDLINK3_MK)
SDL2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.SDL2+=	SDL2>=2.0
BUILDLINK_PKGSRCDIR.SDL2?=	../../wip/SDL2

pkgbase := SDL2
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mnas)
.include "../../audio/nas/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mopengl)
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Moss)
.include "../../mk/oss.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mx11)
.include "../../x11/libX11/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mxcursor)
.include "../../x11/libXcursor/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mxim)
.include "../../x11/libXi/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mxinerama)
.include "../../x11/libXinerama/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mxrandr)
.include "../../x11/libXrandr/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mxrender)
.include "../../x11/libXrender/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.SDL2:Mxscrnsaver)
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# SDL2_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2
