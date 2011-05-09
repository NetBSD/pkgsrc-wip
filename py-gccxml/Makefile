# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:13:21 jihbed Exp $
#

DISTNAME=	pygccxml-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	http://garr.dl.sourceforge.net/project/pygccxml/pygccxml/pygccxml-1.0/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.language-binding.net/
COMMENT=	Python package for easy C++ declarations navigation
#LICENSE=	boost-licence

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/unittests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_all.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
