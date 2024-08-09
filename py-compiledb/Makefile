# $NetBSD$

DISTNAME=	compiledb-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=nickdiego/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nickdiego/compiledb
COMMENT=	Generate Clang JSON Compilation Database files for make-based build systems
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-shutilwhich>=0:../../wip/py-shutilwhich
DEPENDS+=	${PYPKGPREFIX}-bashlex>=0:../../shells/py-bashlex

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27
WRKSRC=		${WRKDIR}/${DISTNAME}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} compiledb compiledb-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
