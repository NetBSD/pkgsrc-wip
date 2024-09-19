# $NetBSD: Makefile,v 1.3 2013/04/19 11:27:28 othyro Exp $
#

DISTNAME=	ttf-arphic-ukai-0.2.20080216.1-6-any.pkg
PKGNAME=	${DISTNAME:S/ttf-arphic-ukai_/arphic-ukai-ttf-/:S/-any.pkg//}
CATEGORIES=	fonts chinese
MASTER_SITES=	http://ftp5.gwdg.de/pub/linux/archlinux/extra/os/x86_64/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/CJKUnifonts
COMMENT=	High-quality Chinese Unicode TrueType font, Kaiti style
LICENSE=	arphic-public

WRKSRC=		${WRKDIR}

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none
EXTRACT_SUFX=	.tar.xz

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR} ${FONTDIR}
FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTDIR}

INSTALL_FONTS=	ukai.ttc
INSTALL_DOCS=	COPYING

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/usr/share/fonts/TTF/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/usr/share/licenses/ttf-arphic-ukai/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
