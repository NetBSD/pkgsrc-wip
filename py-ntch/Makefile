# $NetBSD: Makefile,v 1.8 2012/11/14 00:16:15 othyro Exp $
#

DISTNAME=	pyntch-dist-20090907
CATEGORIES=	devel
MASTER_SITES=	http://www.unixuser.org/~euske/python/pyntch/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.unixuser.org/~euske/python/pyntch/index.html
COMMENT=	Examine python code and detect possible errors
#LICENSE=	LICENSE

VERSION=	20090615

PYDISTUTILSPKG=		yes

DOCDIR=		${PREFIX}/share/doc/py-ntch

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* \
		${DESTDIR}${DOCDIR}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
