# $NetBSD$

DISTNAME=	slclust_02022010
PKGNAME=	slclust-0.0.0.20100202
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=slclust/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/slclust/
COMMENT=	Single-linkage clustering with Jaccard similarity
LICENSE=	artistic

USE_LANGUAGES=	c++

WRKSRC=			${WRKDIR}/slclust
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/slclust ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
