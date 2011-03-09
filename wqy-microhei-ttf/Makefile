# $NetBSD: Makefile,v 1.1.1.1 2011/03/09 19:58:45 ryo-on Exp $
#

DISTNAME=	wqy-microhei-0.2.0-beta
PKGNAME=	${DISTNAME:S/-beta//}
CATEGORIES=	fonts chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wqy/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://wenq.org/enindex.cgi?ZenHei%28en%29
COMMENT=	WenQuanYi Open Source Outline Fonts based on Droid font
LICENSE=	apache-2.0 OR gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wqy-microhei
USE_LANGUAGES=	# none

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLED_FONTS=	wqy-microhei.ttc

INSTALLED_DOCS=		AUTHORS.txt \
			ChangeLog.txt \
			INSTALL.txt \
			LICENSE_Apache2.txt \
			LICENSE_GPLv3.txt \
			README.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/${INSTALLED_FONTS} ${DESTDIR}${FONTDIR}
.for f in ${INSTALLED_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
