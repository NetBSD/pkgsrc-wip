# $NetBSD: Makefile,v 1.3 2012/10/23 10:23:06 thomasklausner Exp $

DISTNAME=	WindowMaker-0.95.2
PKGNAME=	${DISTNAME:S/WindowMaker/windowmaker/}
CATEGORIES=	x11 wm windowmaker
MASTER_SITES=	http://windowmaker.org/pub/source/release/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://windowmaker.org/
COMMENT=	GNUStep-compliant NEXTSTEP(tm) window manager clone

LICENSE=	gnu-gpl-v2

#BROKEN_GETTEXT_DETECTION=	yes

USE_TOOLS+=		msgfmt pkg-config
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-usermenu
CONFIGURE_ARGS+=	--enable-xinerama
CONFIGURE_ARGS+=	--enable-xrandr
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-gnustepdir=${PREFIX}/share/GNUstep
CONFIGURE_ARGS+=	--with-nlsdir=${PREFIX}/${PKGLOCALEDIR}/locale
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib
CONFIGURE_ENV+=		LINGUAS=yes
CONFIGURE_ENV+=		CPP_PATH=${CPP:Q}
USE_TOOLS+=		perl:run
REPLACE_PERL+=		util/wkdemenu.pl

INSTALLATION_DIRS=	share/WindowMaker/SoundSets
INSTALLATION_DIRS+=	share/WindowMaker/Sounds
INSTALLATION_DIRS+=	share/doc/WindowMaker

PKG_SYSCONFSUBDIR=	WindowMaker
EGDIR=			${PREFIX}/share/examples/WindowMaker
CONF_FILES=
.for f in WMGLOBAL WMRootMenu WMState WMWindowAttributes WindowMaker
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

post-extract:
	${RM} -f ${WRKSRC}/WindowMaker/Defaults/WMState \
		 ${WRKSRC}/WindowMaker/Defaults/WMWindowAttributes \
		 ${WRKSRC}/WindowMaker/Defaults/WindowMaker \
		 ${WRKSRC}/po/zh_TW.Big5.po
	set -e; \
	for manfile in ${WRKSRC}/doc/*.1x ${WRKSRC}/doc/*/*.1x; \
	do \
		${MV} "$$manfile" `${ECHO} "$$manfile" | ${SED} "s/1x$$/1/"`; \
	done;
	set -e; \
	cd ${WRKSRC} && \
	for f in WINGs/wapplication.c WindowMaker/Defaults/WindowMaker.in \
		WPrefs.app/Paths.c WindowMaker/menu* WindowMaker/plmenu*; do \
		${SED}	-e "s|/usr/local|${PREFIX}|g" \
			-e "s|${PREFIX}/GNUstep|${PREFIX}/share/GNUstep|g" \
			"$$f" > "$$f".new && \
		${MV} "$$f".new "$$f"; \
	done

post-install:
	${TOUCH} ${DESTDIR}${PREFIX}/share/WindowMaker/SoundSets/.directory
	${TOUCH} ${DESTDIR}${PREFIX}/share/WindowMaker/Sounds/.directory
	cd ${WRKSRC} && \
	${INSTALL_DATA} \
		README README.definable-cursor FAQ FAQ.I18N \
		${DESTDIR}${PREFIX}/share/doc/WindowMaker

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
BUILDLINK_DEPMETHOD.libXt?=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
