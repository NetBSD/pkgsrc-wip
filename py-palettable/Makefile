# $NetBSD$

DISTNAME=	palettable-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	https://files.pythonhosted.org/packages/8d/b5/30ebe2978d4e4ddc0bfa9e042ec6fad16cc390d108b8cbee0c5ebd417df4/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://jiffyclub.github.io/palettable/
COMMENT=	Color palettes for Python
#LICENSE=	

do-test:
	${RUN} cd ${WRKSRC}/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_installed.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
