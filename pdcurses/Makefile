# $NetBSD$

DISTNAME=	PDCurses-3.9
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdcurses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pdcurses.sourceforge.io/
COMMENT=	Public domain implementation of the X/Open curses standard
LICENSE=	gnu-gpl-v3 AND mit AND public-domain

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		x11
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}

# PDCURSES_XAW is the name of the Xaw library.
#
# XXX This information should really be provided by the various Xaw-like
# XXX buildlink3.mk files.
#
BUILD_DEFS+=		XAW_TYPE
PDCURSES_XAW.3d=	Xaw3d
PDCURSES_XAW.neXtaw=	neXtaw
PDCURSES_XAW.xpm=	Xaw3d
PDCURSES_XAW.standard=	Xaw
PDCURSES_XAW=		${PDCURSES_XAW.${XAW_TYPE}}
CONFIGURE_ENV+=		PDCURSES_XAW=${PDCURSES_XAW:Q}

REPLACE_SH=		x11/xcurses-config.in
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/MANUAL.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/USERS.md ${DESTDIR}${DOCDIR}

.include "../../mk/xaw.buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
