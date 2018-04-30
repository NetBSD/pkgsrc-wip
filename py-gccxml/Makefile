# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:47 othyro Exp $
#

DISTNAME=	pygccxml-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygccxml/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.language-binding.net/
COMMENT=	Python package for easy C++ declarations navigation
LICENSE=	boost-licence

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/unittests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
