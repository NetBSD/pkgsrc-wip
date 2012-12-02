# $NetBSD: buildlink3.mk,v 1.3 2012/12/02 02:21:23 othyro Exp $

BUILDLINK_TREE+=	mupen64plus

.if !defined(MUPEN64PLUS_BUILDLINK3_MK)
MUPEN64PLUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupen64plus+=	mupen64plus>=1.99.5nb1
BUILDLINK_PKGSRCDIR.mupen64plus?=	../../wip/mupen64plus

pkgbase := mupen64plus
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.mupen64plus:Mlirc)
.include "../../comms/lirc/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.mupen64plus:Msamplerate)
.include "../../audio/libsamplerate/buildlink3.mk"
.endif

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.endif	# MUPEN64PLUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupen64plus
