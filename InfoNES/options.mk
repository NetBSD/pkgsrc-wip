# $NetBSD: options.mk,v 1.3 2007/03/15 18:44:18 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.InfoNES
PKG_OPTIONS_REQUIRED_GROUPS=	frontend
PKG_OPTIONS_GROUP.frontend=	gtk sdl
PKG_SUGGESTED_OPTIONS+=	gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path.
SUBST_FILES.dsp=	src/linux/InfoNES_System_Linux.cpp
SUBST_SED.dsp=		-e "s|/dev/dsp|${DEVOSSAUDIO}|"

SRC_SUBDIR=		linux

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msdl)
SRC_SUBDIR=		sdl
.include "../../devel/SDL/buildlink3.mk"
.endif
