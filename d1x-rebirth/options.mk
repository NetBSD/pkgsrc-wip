# $NetBSD: options.mk,v 1.1 2015/08/19 19:06:08 yhardy Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.d1x-rebirth
PKG_SUPPORTED_OPTIONS=		raspberrypi
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mraspberrypi)
SCONS_ARGS+=	raspberrypi=1
SCONS_ARGS+=	rpi_vc_path=${PREFIX}
.endif

.if !empty(PKG_OPTIONS:Mraspberrypi)
.include "../../misc/raspberrypi-userland/buildlink3.mk"
.endif
