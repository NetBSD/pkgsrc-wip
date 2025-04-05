# $NetBSD$

DISTNAME=	fasda-utils-0.1.0
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda-utils
COMMENT=	Fast and simple differential analysis extras
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-seaborn>0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-fastcluster>0:../../wip/py-fastcluster

REPLACE_PYTHON=	Scripts/heatmap.py

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
