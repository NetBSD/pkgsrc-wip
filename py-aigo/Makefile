# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:45 thomasklausner Exp $

DISTNAME=	AIGO-0.1.0
PKGNAME=	${PYPKGPREFIX}-aigo-0.1.0
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=A/AIGO/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/aigo/
COMMENT=	Analysis and Inter-comparison of Gene Ontology functional annotations
LICENSE=	gnu-gpl-v3

CONFLICTS=	${PYPKGPREFIX}-creole-[0-9]*
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-wxWidgets

post-extract:
	${MV} ${WRKSRC}/bin/AIGO-gui.py ${WRKSRC}/bin/AIGO-gui.py${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testAIGO.py

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
