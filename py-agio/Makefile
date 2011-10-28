# $NetBSD: Makefile,v 1.1.1.1 2011/10/28 17:00:38 jihbed Exp $
#

DISTNAME=	AIGO-0.1.0
PKGNAME=	${PYPKGPREFIX}-aigo-0.1.0
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/A/AIGO/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/aigo/
COMMENT=	Analysis and Inter-comparison of Gene Ontology functional annotations
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/AIGO-gui.py ${WRKSRC}/bin/algio-gui.py${PYVERSSUFFIX}

do-test:
	${RUN} cd ${WRKSRC}/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} testAIGO.py

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../x11/py-wxWidgets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
