# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.cliqz

PKG_SUPPORTED_OPTIONS+=	alsa pulseaudio dbus

PKG_SUGGESTED_OPTIONS+=	pulseaudio dbus

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-alsa"
.include "../../audio/alsa-lib/buildlink3.mk"
.else
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-alsa"
.endif

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
.  if ${CC_VERSION:S/gcc-//:S/.//g} >= 480
# Modern gcc does not run any "tracking" passes when compiling with -O0,
# which makes the generated debug info mostly useless. So explicitly
# request them.
O0TRACKING=-fvar-tracking-assignments -fvar-tracking
.  endif
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-pulseaudio"
.else
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-pulseaudio"
.endif

.if !empty(PKG_OPTIONS:Mdbus)
.include "../../sysutils/dbus-glib/buildlink3.mk"
MOZ_CONFIGURE_ARGS+=	"ac_add_options --enable-dbus"
.else
MOZ_CONFIGURE_ARGS+=	"ac_add_options --disable-dbus"
.endif
