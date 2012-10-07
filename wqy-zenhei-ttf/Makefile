# $NetBSD: Makefile,v 1.3 2012/10/07 20:11:08 asau Exp $
#

DISTNAME=	wqy-zenhei-0.8.38-1
PKGNAME=	wqy-zenhei-0.8.38.1
PKGREVISION=	1
CATEGORIES=	fonts chinese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wqy/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://wenq.org/enindex.cgi?ZenHei%28en%29
COMMENT=	WenQuanYi Open Source Outline Fonts (Chinese simplified)
LICENSE=	gnu-gpl-v2 # with font embedding exception

WRKSRC=		${WRKDIR}/wqy-zenhei
USE_LANGUAGES=	# none

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
EXAMPLEDIR=	${PREFIX}/share/examples/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCDIR} \
			${EXAMPLEDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLED_FONTS=	wqy-zenhei.ttc

INSTALLED_DOCS=		AUTHORS \
			ChangeLog \
			INSTALL \
			README \
			COPYING

INSTALLED_EXAMPLES=	44-wqy-zenhei.conf \
			66-wqy-zenhei-sharp-no13px.conf \
			66-wqy-zenhei-sharp.conf

do-install:
	${INSTALL_DATA} ${WRKSRC}/${INSTALLED_FONTS} ${DESTDIR}${FONTDIR}/wqy-zenhei.ttf
.for f in ${INSTALLED_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
.for f in ${INSTALLED_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${EXAMPLEDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
