# $NetBSD: Makefile,v 1.1.1.1 2010/07/14 13:11:02 jihbed Exp $
#

DISTNAME=	DecoratorTools-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/D/d/S/T/t/}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/D/DecoratorTools/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/DecoratorTools
COMMENT=	Class, function, and metaclass decorators

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DOCDIR=	${PREFIX}/share/doc/py-decoratortools

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_decorators

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
