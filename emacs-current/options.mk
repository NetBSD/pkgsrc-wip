# $NetBSD: options.mk,v 1.6 2008/07/27 06:32:38 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs_current
PKG_SUPPORTED_OPTIONS=	gnome font-backend
PKG_OPTIONS_OPTIONAL_GROUPS+= window-system
PKG_OPTIONS_GROUP.window-system= x11 carbon nextstep
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
CONFIGURE_ARGS+=	--without-carbon

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
.include "../../graphics/libotf/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
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
.  else
.include "../../devel/gnustep-base/buildlink3.mk"
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

###
### Support Carbon Emacs
###
.  if !empty(PKG_OPTIONS:Mcarbon)
.    if !exists(/System/Library/Frameworks/Carbon.framework)
PKG_FAIL_REASON=	"This platform doesn't support Carbon"
.    else
APPLICATIONS_DIR=	Applications

CONFIGURE_ARGS+=	--with-carbon
CONFIGURE_ARGS+=	--enable-carbon-app=${PREFIX}/${APPLICATIONS_DIR}

PLIST_SRC+=		PLIST.carbon
PLIST_SUBST+=		APPLIDATIONS_DIR=${APPLICATIONS_DIR:Q}

INSTALLATION_DIRS=	${APPLICATIONS_DIR}

CHECK_WRKREF_SKIP+=	${APPLICATIONS_DIR}/Emacs.app/Contents/MacOS/Emacs

post-install:
	for d in `find ${DESTDIR}${PREFIX}/${APPLICATIONS_DIR}/Emacs.app -type d ! -name CVS -print`; do  \
		rm -rf $${d}/CVS; \
		rm -rf $${d}/.cvsignore; \
	done

.    endif
.  else
CONFIGURE_ARGS+=	--without-carbon
.  endif
.endif
