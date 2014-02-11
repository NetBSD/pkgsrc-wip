# $NetBSD: Makefile,v 1.7 2014/02/11 20:51:01 jihbed Exp $

DISTNAME=	pp-1.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	parallel python
MASTER_SITES=	http://www.parallelpython.com/downloads/pp/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.parallelpython.com/
COMMENT=	Parallel and distributed programming for Python
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/py-pp

post-extract:
	cd ${WRKSRC} && ${MV} ppserver.py ppserver${PYVERSSUFFIX}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ppserver.1\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/ppdoc.html\
			${DESTDIR}${PREFIX}/share/doc/py-pp

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
