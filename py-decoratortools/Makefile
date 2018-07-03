# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:25 thomasklausner Exp $

DISTNAME=	DecoratorTools-1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/D/d/S/T/t/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=D/DecoratorTools/}
EXTRACT_SUFX=	.zip
LICENSE=	python-software-foundation # or ZPL

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/DecoratorTools
COMMENT=	Class, function, and metaclass decorators

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.8

DOCDIR=	${PREFIX}/share/doc/py-decoratortools

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test_decorators

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
