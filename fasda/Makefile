# $NetBSD$

DISTNAME=	fasda-0.1.5.57
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_GITHUB:=auerlab/}
GITHUB_TAG=	c080ebac7223e85f4cb424d4423b9b2e78c23259

OWNER=		bacon@NetBSD.org
HOMEPAGE=	https://github.com/auerlab/fasda
COMMENT=	Fast and simple differential analysis
LICENSE=	2-clause-bsd

DEPENDS=	stringtie>0:../../wip/stringtie
DEPENDS+=	${PYPKGPREFIX}-seaborn>0:../../graphics/py-seaborn
DEPENDS+=	${PYPKGPREFIX}-fastcluster>0:../../wip/py-fastcluster

REPLACE_PYTHON=	Scripts/heatmap.py

LDFLAGS.SunOS+=	-lresolv
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR} VERSION=${PKGVERSION}

.include "../../wip/biolibc/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
