# $NetBSD: buildlink3.mk,v 1.4 2013/05/07 11:25:01 othyro Exp $

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

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# SDL2_BUILDLINK3_MK

BUILDLINK_TREE+=	-SDL2
