# $NetBSD: Makefile,v 1.6 2014/12/31 13:58:44 thomasklausner Exp $

DISTNAME=	tappy-0.8.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tappy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://tappy.sourceforge.net/
COMMENT=	Tidal analysis program in python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.8.3

post-extract:
	${MV} ${WRKSRC}/tappy.py  ${WRKSRC}/tappy${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}; ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/test_tappy.py

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
