# $NetBSD: options.mk,v 1.3 2011/03/02 21:52:00 gschwarz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.linphone
PKG_SUPPORTED_OPTIONS=	alsa inet6 linphone-gui linphone-video
PKG_SUGGESTED_OPTIONS=	linphone-gui linphone-video

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.endif

.if empty(PKG_OPTIONS:Mlinphone-gui)
CONFIGURE_ARGS+=	--enable-gnome_ui=no
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
PLIST_SUBST+=	GUI="@comment "
.else
PLIST_SUBST+=	GUI=
CONFIGURE_ARGS+=	--enable-gnome_ui=yes
.include "../../x11/gnome-panel/buildlink3.mk"
.endif

.if empty(PKG_OPTIONS:Mlinphone-gui) || empty(PKG_OPTIONS:Mlinphone-video)
CONFIGURE_ARGS+=	--enable-video=no
.else
CONFIGURE_ARGS+=	--enable-video=yes
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
