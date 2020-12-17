# $NetBSD$

DISTNAME=	gwcs-0.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_GITHUB:=spacetelescope/}
GITHUB_PROJECT=	gwcs
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gwcs.readthedocs.io/en/latest/
COMMENT=	Generalized World Coordinate System
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE+=	27
PYTHON_VERSIONS_INCOMPATIBLE+=	36

DEPENDS+=	git>=2:../../devel/git
DEPENDS+=	${PYPKGPREFIX}-astropy4>=4.2:../../wip/py-astropy
DEPENDS+=	${PYPKGPREFIX}-asdf>=2.7.1:../../wip/py-asdf

pre-configure:
	set -e; cd ${WRKSRC}; \
	git init;

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
