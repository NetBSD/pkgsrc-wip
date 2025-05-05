# $NetBSD$

DISTNAME=	fasda-utils-0.1.0.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	f9217f056048625f5cb9884b8e1d25204bdf1f25

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
