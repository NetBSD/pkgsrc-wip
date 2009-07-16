# $NetBSD: Makefile,v 1.1.1.1 2009/07/16 17:47:53 jihbed Exp $
#

DISTNAME=	decorator-3.0.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/d/decorator/
EXTRACT_SUFX=	.gz#md5=c4130a467be7f71154976c84af4a04c6

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/decorator
COMMENT=	Simplify usage of python decorators by programmers
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/decorator-3.0.1
USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 25 24

DOCDIR=		${PREFIX}/share/doc/py-decorator

#INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.pdf \
		${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation.html \
		${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
