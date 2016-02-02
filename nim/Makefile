# $NetBSD$

DISTNAME=	nim-0.13.0
CATEGORIES=	lang
MASTER_SITES=	http://nim-lang.org/download/
EXTRACT_SUFX=	.tar.xz
LICENSE=	mit

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	The Nim programming language

NO_CONFIGURE=	yes

do-build:
	cd ${WRKSRC} && sh ./build.sh

do-install:
	cd ${WRKSRC} && sh ./install.sh ${DESTDIR}${PREFIX}

.include "../../mk/bsd.pkg.mk"
