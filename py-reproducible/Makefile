# $NetBSD$

GITHUB_PROJECT=	reproducible
GITHUB_TAG=	v0.4.0
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=oist-cnru/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/oist-cnru/reproducible
COMMENT=	Reproducible library
LICENSE=	gnu-lgpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-gitpython>=3.1.11:../../devel/py-gitpython
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-cpuinfo>=6.0.0:../../sysutils//py-cpuinfo

WRKSRC=		${WRKDIR}/reproducible-0.4.0

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
