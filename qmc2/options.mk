# $NetBSD: options.mk,v 1.1 2013/03/04 17:33:01 othyro Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.qmc2
PKG_SUPPORTED_OPTIONS=	gstreamer mame mess phonon sdl vlc xine
PKG_SUGGESTED_OPTIONS=	mame phonon sdl xine
#PLIST_VARS+=		gstreamer mame mess phonon sdl vlc xine

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
#PLIST.gstreamer=	yes
.endif

.if !empty(PKG_OPTIONS:Mmame)
DEPENDS+=	mame-[0-9]*:../../emulators/mame
EMULATOR=	SDLMAME
#PLIST.mame=	yes
.endif

.if !empty(PKG_OPTIONS:Mmess)
DEPENDS+=	mess-[0-9]*:../../emulators/mess
EMULATOR=	SDLMESS
#PLIST.mess=	yes
.endif

.if !empty(PKG_OPTIONS:Mphonon)
.include "../../multimedia/phonon/buildlink3.mk"
#PLIST.phonon=	yes
.else
MAKE_ENV+=	PHONON=0
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
#PLIST.sdl=	yes
.else
MAKE_ENV+=	JOYSTICK=0
.endif

.if !empty(PKG_OPTIONS:Mvlc)
.include "../../multimedia/vlc/buildlink3.mk"
#PLIST.vlc=	yes
.endif

.if !empty(PKG_OPTIONS:Mxine)
.include "../../multimedia/xine-lib/buildlink3.mk"
#PLIST.xine=	yes
.endif

.if empty(PKG_OPTIONS:Mgstreamer) && empty((PKG_OPTIONS:Mvlc) && empty(PKG_OPTIONS:Mxine)
MAKE_ENV+=	YOUTUBE=0
.endif
