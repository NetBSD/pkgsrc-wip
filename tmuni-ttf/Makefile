# $NetBSD: Makefile,v 1.2 2011/11/04 07:12:45 phonohawk Exp $
#

DISTNAME=		ttf-tmuni_1.901b.orig
PKGNAME=		tmuni-ttf-1.901b
CATEGORIES=		fonts
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/ttf-tmuni/}

MAINTAINER=		pho@cielonegro.org
HOMEPAGE=		http://www.thlib.org/tools/scripts/wiki/tibetan%20machine%20uni.html
COMMENT=		Unicode Font for Tibetan, Dzongkha and Ladakhi
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${DISTNAME:S/_/-/}
NO_BUILD=		YES
NO_CONFIGURE=	YES

PKG_DESTDIR_SUPPORT=	user-destdir

FONTS_DIRS.ttf=		${PREFIX}/lib/X11/fonts/TTF
INSTALLATION_DIRS+=	${FONTS_DIRS.ttf}

DOCDIR=				${PREFIX}/share/doc/${PKGNAME}
INSTALLATION_DIRS+=	${DOCDIR}

do-install:
	${INSTALL_DATA}	${WRKSRC}/TibMachUni-${PKGVERSION}.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA}	${WRKSRC}/ReadMe.txt                   ${DESTDIR}${DOCDIR}
	${INSTALL_DATA}	${WRKSRC}/gpl.txt                      ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
