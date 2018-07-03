# $NetBSD: Makefile,v 1.8 2014/02/12 21:48:01 jihbed Exp $

DISTNAME=	pp-1.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	http://www.parallelpython.com/downloads/pp/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.parallelpython.com/
COMMENT=	Parallel and distributed programming for Python
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 1.6.4

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/py-pp

post-extract:
	cd ${WRKSRC} && ${MV} ppserver.py ppserver${PYVERSSUFFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ppserver.1\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/ppdoc.html\
			${DESTDIR}${PREFIX}/share/doc/py-pp

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
