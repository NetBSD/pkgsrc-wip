# $NetBSD: options.mk,v 1.11 2008/12/04 21:40:54 minskim Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs_current
PKG_SUPPORTED_OPTIONS=	gnome font-backend
PKG_OPTIONS_OPTIONAL_GROUPS+= window-system
PKG_OPTIONS_GROUP.window-system= x11 nextstep
PKG_OPTIONS_OPTIONAL_GROUPS+= toolkit
PKG_OPTIONS_GROUP.toolkit= gtk motif xaw
PKG_SUGGESTED_OPTIONS=	x11

.include "../../mk/bsd.options.mk"

###
### Any of the "toolkit" options implies "x11".
###
.if !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mxaw) || !empty(PKG_OPTIONS:Mgnome) || !empty(PKG_OPTIONS:Mfont-backend)
.  if empty(PKG_OPTIONS:Mx11)
PKG_OPTIONS+=		x11
.  endif
.endif

###
### Default to using the Xaw X11 toolkit if none is specified.
###
.if !empty(PKG_OPTIONS:Mx11)
.  if empty(PKG_OPTIONS:Mgtk) && empty(PKG_OPTIONS:Mmotif) && empty(PKG_OPTIONS:Mxaw)
.    if !empty(PKG_OPTIONS:Mgnome)
PKG_OPTIONS+=		gtk
.    else
PKG_OPTIONS+=		xaw
.    endif
.  endif
.endif

###
### Support drawing pretty X11 widgets.
###
.if !empty(PKG_OPTIONS:Mx11)

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-png

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

###
### Support gnome features
###
.  if !empty(PKG_OPTIONS:Mgnome)
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.  endif

###
### Enable font backend
###
.  if !empty(PKG_OPTIONS:Mfont-backend)
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/libotf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../devel/m17n-lib/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-font-backend
.  else
CONFIGURE_ARGS+=	--disable-font-backend
.  endif

###
### Support using GTK X11 widgets.
###
.  if !empty(PKG_OPTIONS:Mgtk)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk

###
### Support using Motif X11 widgets.
###
.  elif !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif

###
### Support using Xaw (Lucid) X11 widgets.
###
.  elif !empty(PKG_OPTIONS:Mxaw)
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.  endif

###
### Support using NextStep (Cocoa or GNUstep) windwing system
###
.elif !empty(PKG_OPTIONS:Mnextstep)
.  if exists(/System/Library/Frameworks/Cocoa.framework)
APPLICATIONS_DIR=	Applications
NS_APPBINDIR=		nextstep/Emacs.app/Contents/MacOS
PLIST_SRC+=		PLIST.cocoa
CHECK_WRKREF_SKIP+=	Applications/Emacs.app/Contents/MacOS/Emacs
.  else
.include "../../devel/gnustep-base/buildlink3.mk"
MAKE_FILE=		Makefile
APPLICATIONS_DIR=	share/GNUstep/Local/Applications
NS_APPBINDIR=		nextstep/Emacs.app
PLIST_SRC+=		PLIST.gnustep
.  endif
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--with-ns
CONFIGURE_ARGS+=	--disable-ns-self-contained

INSTALLATION_DIRS+=	${APPLICATIONS_DIR}
USE_TOOLS+=		pax

post-install:
	cd ${WRKSRC}/nextstep && \
		pax -rw -pp -pm Emacs.app ${DESTDIR}${PREFIX}/${APPLICATIONS_DIR}

.else
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-xpm
CONFIGURE_ARGS+=	--without-jpeg
CONFIGURE_ARGS+=	--without-tiff
CONFIGURE_ARGS+=	--without-gif
CONFIGURE_ARGS+=	--without-png
.endif
