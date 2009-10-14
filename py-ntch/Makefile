# $NetBSD: Makefile,v 1.4 2009/10/14 14:40:39 jihbed Exp $
#

DISTNAME=	pyntch-dist-20090907
CATEGORIES=	wip
MASTER_SITES=	http://www.unixuser.org/~euske/python/pyntch/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.unixuser.org/~euske/python/pyntch/index.html
COMMENT=	Examine python code and detect possible errors
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=		user-destdir

VERSION=	20090615

PYDISTUTILSPKG= 	yes
PYTHON_VERSIONS_ACCEPTED= 26 25 24

DOCDIR=		${PREFIX}/share/doc/py-ntch

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* \
		${DESTDIR}${DOCDIR}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
