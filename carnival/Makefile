# $NetBSD: Makefile,v 1.1.1.1 2012/01/04 19:10:40 noud4 Exp $
#

DISTNAME=		carnival-1.03-src
PKGNAME=		${DISTNAME:S|-src||}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=carnival/}
EXTRACT_SUFX=		.zip

MAINTAINER=		noud4@home.nl
HOMEPAGE=		http://carnival.sourceforge.net/
COMMENT=		GUI for Festival
LICENSE=		gnu-gpl-v1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/
USE_LANGUAGES=  	c++
USE_TOOLS+=     	gmake
MAKE_FILE=		makefile.unx

DOCS=			sable.htm ssml.htm
DOCDIR=			share/doc/carnival

INSTALLATION_DIRS+=	bin  ${DOCDIR} ${XDG_DIR} share/pixmaps

XDG_DESKTOP=		carnival.desktop
XDG_DIR=		share/applications

PLIST_SUBST+=		DOCDIR=${DOCDIR}
PLIST_SUBST+=		XDG_DESKTOP=${XDG_DESKTOP}

post-extract:
	${CP} ${FILESDIR}/${XDG_DESKTOP} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/carnival ${DESTDIR}${PREFIX}/bin
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/${XDG_DESKTOP} ${DESTDIR}${PREFIX}/${XDG_DIR}
	${INSTALL_DATA} ${WRKSRC}/carnival.xpm ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../x11/wxGTK24/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
