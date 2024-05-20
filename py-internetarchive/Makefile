# $NetBSD$

DISTNAME=	internetarchive-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/internetarchive/}

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://github.com/jjjake/internetarchive
COMMENT=	Interface to the internet archive
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-docopt-[0-9]*:../../devel/py-docopt
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif
DEPENDS+=	${PYPKGPREFIX}-jsonpatch-[0-9]*:../../wip/py-jsonpatch
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-schema-[0-9]*:../../wip/py-schema
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

post-install:
	cd ${DESTDIR}${PREFIX} &&					\
		${MV} bin/ia bin/ia-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
