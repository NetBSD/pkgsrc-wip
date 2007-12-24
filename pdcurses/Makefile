# $NetBSD: Makefile,v 1.2 2007/12/24 18:52:00 bsadewitz Exp $
#

DISTNAME=	PDCurses-3.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdcurses/}

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://pdcurses.sourceforge.net/
COMMENT=	Public domain implementation of the X/Open curses standard

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.Xaw}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.Xaw}/lib
CONFIGURE_ENV+=		PDCURSES_LIBXAW=${PDCURSES_LIBXAW:Q}

PDCURSES_LIBXAW.3d=		Xaw3d
PDCURSES_LIBXAW.neXtaw=		neXtaw
PDCURSES_LIBXAW.xpm=		Xaw3d
PDCURSES_LIBXAW.standard= 	Xaw${LIBXAW_SUFX:U}
PDCURSES_LIBXAW=		${PDCURSES_LIBXAW.${XAW_TYPE}}

.if !empty(XAW_TYPE:M[n3x][edp]*)
CONFIGURE_ARGS+=	--with-${PDCURSES_LIBXAW}
.elif ${X11_TYPE} == "modular"
LIBXAW_SUFX=		${BUILDLINK_TRANSFORM:M*Xaw[0-9]:C/[^[0-9]]*//g}
.endif

PDBINDIR=		${DESTDIR}${PREFIX}/bin
PDLIBDIR=		${DESTDIR}${PREFIX}/lib
PDMANDIR=		${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
PDDOCDIR=		${DESTDIR}${PREFIX}/share/doc/pdcurses
PDINCDIR=		${DESTDIR}${PREFIX}/include
PDINCDIR.xcurses=	${PDINCDIR}/xcurses

REPLACE_SH=		x11/xcurses-config

.include "../../mk/xaw.buildlink3.mk"

.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

SUBST_CLASSES+=		hdr
SUBST_STAGE.hdr=	post-build
SUBST_FILES.hdr=	panel.h
SUBST_SED.hdr=		-e 's,\#include <curses.h>,\#include <xcurses.h>,'
SUBST_MESSAGE.hdr=	Preparing for installation: ${SUBST_FILES.hdr}.

pre-install:
	cp ${WRKSRC}/panel.h ${WRKSRC}/xpanel.h

do-install:
	${RUN} ${INSTALL_LIB_DIR} ${PDLIBDIR:Q} &&			\
	${INSTALL_SCRIPT_DIR} ${PDBINDIR:Q} &&				\
	${INSTALL_DATA_DIR} ${PDINCDIR:Q} &&				\
	${INSTALL_DATA_DIR} ${PDDOCDIR:Q} &&				\
	${INSTALL_DATA_DIR} ${PDINCDIR.xcurses:Q} &&			\
	${LIBTOOL} --mode=install ${INSTALL_LIB} 			\
		${WRKSRC}/x11/libXCurses.la ${PDLIBDIR:Q}/ &&		\
	${LIBTOOL} --mode=install ${INSTALL_LIB} 			\
		${WRKSRC}/x11/libxpanel.la ${PDLIBDIR:Q}/ &&		\
	${INSTALL_DATA} ${WRKSRC}/curses.h ${PDINCDIR:Q}/xcurses.h &&	\
	${INSTALL_DATA} ${WRKSRC}/curses.h ${PDINCDIR.xcurses:Q} &&	\
	${INSTALL_DATA} ${WRKSRC}/xpanel.h ${PDINCDIR:Q} &&		\
	${INSTALL_DATA} ${WRKSRC}/panel.h ${PDINCDIR.xcurses:Q} &&	\
	${INSTALL_DATA} ${WRKSRC}/curspriv.h ${PDINCDIR.xcurses:Q} &&	\
	${INSTALL_DATA} ${WRKSRC}/term.h ${PDINCDIR.xcurses:Q} &&	\
	${INSTALL_SCRIPT} ${WRKSRC}/x11/xcurses-config ${PDBINDIR:Q} &&	\
	${INSTALL_DATA} ${WRKSRC}/tools/PDCurses.man ${PDDOCDIR:Q}

.include "../../mk/bsd.pkg.mk"
