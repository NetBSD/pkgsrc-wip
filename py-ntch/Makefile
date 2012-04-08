# $NetBSD: Makefile,v 1.6 2012/04/08 19:09:48 thomasklausner Exp $
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

DOCDIR=		${PREFIX}/share/doc/py-ntch

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* \
		${DESTDIR}${DOCDIR}


.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
