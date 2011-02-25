# $NetBSD: Makefile,v 1.6 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	decorator-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/d/decorator/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/decorator
COMMENT=	Simplify usage of python decorators by programmers
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/decorator-3.2.0
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24

DOCDIR=		${PREFIX}/share/doc/py-decorator

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.pdf \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.html \
		${DESTDIR}${DOCDIR}


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
