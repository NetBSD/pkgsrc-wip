# $NetBSD$

DISTNAME=	fasda-utils-0.1.0.5
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	756fe6ee34e97407c3f2b4bd84ef92b9b697915c

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda-utils
COMMENT=	Fast and simple differential analysis extras
LICENSE=	2-clause-bsd

DEPENDS+=	fasda>=0.2.0:../../biology/fasda
DEPENDS+=	${PYPKGPREFIX}-seaborn>0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-fastcluster>0:../../math/py-fastcluster
DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

REPLACE_PYTHON=	Scripts/heatmap.py

MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
