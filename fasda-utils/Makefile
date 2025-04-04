# $NetBSD$

DISTNAME=	fasda-utils-0.0.0.3
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	eb807e741241e15db049409e5d401d21d91eb8f2

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda-utils
COMMENT=	Fast and simple differential analysis extras
LICENSE=	2-clause-bsd

DEPENDS+=       ${PYPKGPREFIX}-seaborn>0:../../graphics/py-seaborn
DEPENDS+=       ${PYPKGPREFIX}-fastcluster>0:../../wip/py-fastcluster

REPLACE_PYTHON=	Scripts/heatmap.py

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
