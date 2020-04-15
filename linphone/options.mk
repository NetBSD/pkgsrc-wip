# $NetBSD: options.mk,v 1.6 2014/08/11 23:10:13 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.linphone
PKG_SUPPORTED_OPTIONS=	alsa inet6 linphone-gui linphone-video gsm
PKG_SUGGESTED_OPTIONS=	inet6 linphone-gui linphone-video gsm

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.endif

.if !empty(PKG_OPTIONS:Mlinphone-gui)
PLIST_SUBST+=	GUI=
CONFIGURE_ARGS+=	--enable-gtk_ui=yes
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
PLIST_SUBST+=	GUI="@comment "
.else
CONFIGURE_ARGS+=	--enable-gtk_ui=no
.endif

.if empty(PKG_OPTIONS:Mlinphone-gui) || empty(PKG_OPTIONS:Mlinphone-video)
CONFIGURE_ARGS+=	--enable-video=no
.else
CONFIGURE_ARGS+=	--enable-video=yes
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgsm)
.include "../../audio/gsm/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif
