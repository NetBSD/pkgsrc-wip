# $NetBSD$

DISTNAME=	bincopy-20.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bincopy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eerimoq/bincopy
COMMENT=	Mangling of various binary file formats
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-humanfriendly>=0:../../textproc/py-humanfriendly
DEPENDS+=	${PYPKGPREFIX}-argparse-addons>=0.4.0:../../devel/py-argparse-addons
DEPENDS+=	${PYPKGPREFIX}-pyelftools>=0:../../devel/py-pyelftools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}/${PREFIX}/bin && ${MV} bincopy bincopy-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
