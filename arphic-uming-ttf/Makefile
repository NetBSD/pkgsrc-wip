# $NetBSD: Makefile,v 1.1.1.1 2011/03/09 19:57:56 ryo-on Exp $
#

DISTNAME=	ttf-arphic-uming_0.2.20080216.1.orig
PKGNAME=	${DISTNAME:S/ttf-arphic-uming_/arphic-uming-ttf-/:S/.orig//}
CATEGORIES=	fonts chinese
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/ttf-arphic-uming/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/wiki/Software/CJKUnifonts
COMMENT=	High-quality Chinese Unicode TrueType font, Mingti style
#LICENSE=	Arphic Public License

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	uming.ttc

INSTALL_DOCS=	FONTLOG \
		license/english/ARPHICPL.TXT

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
