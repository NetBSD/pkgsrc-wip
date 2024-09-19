# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:26 asau Exp $
#

DISTNAME=	clnum-1.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/clnum/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/c/clnum/
COMMENT=	Rational and arbitrary precision floating point numbers
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	share/doc/py-clnum

PYDISTUTILSPKG=	yes

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/test_clnum.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/clnumManual.html ${DESTDIR}${PREFIX}/share/doc/py-clnum

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/cln/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
