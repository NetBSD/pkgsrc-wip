# $NetBSD$

DISTNAME=	fasda-utils-0.1.0.1
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	761fb570616e826f9bf4292e2284865c4abfd6a6

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda-utils
COMMENT=	Fast and simple differential analysis extras
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-seaborn>0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-fastcluster>0:../../wip/py-fastcluster

REPLACE_PYTHON=	Scripts/heatmap.py

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
