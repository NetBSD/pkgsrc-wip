# $NetBSD: options.mk,v 1.2 2013/12/07 00:39:22 thomasklausner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qmc2
PKG_SUPPORTED_OPTIONS=		phonon sdl
PKG_OPTIONS_REQUIRED_GROUPS+=	emu
PKG_OPTIONS_GROUP.emu=		mame mess
PKG_SUGGESTED_OPTIONS=		mame phonon sdl
PLIST_VARS+=			mame mess

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmame)
DEPENDS+=	mame-[0-9]*:../../emulators/mame
EMULATOR=	SDLMAME
PLIST.mame=	yes
.endif

.if !empty(PKG_OPTIONS:Mmess)
DEPENDS+=	mess-[0-9]*:../../emulators/mess
EMULATOR=	SDLMESS
PLIST.mess=	yes
.endif

.if !empty(PKG_OPTIONS:Mphonon)
.include "../../multimedia/phonon/buildlink3.mk"
.else
MAKE_ENV+=	PHONON=0
.endif

.if !empty(PKG_OPTIONS:Msdl)
.include "../../devel/SDL/buildlink3.mk"
.else
MAKE_ENV+=	JOYSTICK=0
.endif
