# $NetBSD$

DISTNAME=	conan-1.12.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_PYPI:=c/conan/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://conan.io/
COMMENT=	C/C++ package manager
LICENSE=	mit

USE_LANGUAGES=	# none


post-install:
	cd ${DESTDIR}${PREFIX}/bin && for b in conan conan_build_info conan_server; \
          do ${MV} $$b $$b-${PYVERSSUFFIX}; \
        done

DEPENDS+=   ${PYPKGPREFIX}-pluginbase-0.7:../../wip/py-pluginbase
DEPENDS+=   ${PYPKGPREFIX}-bottle:../../www/py-bottle
DEPENDS+=   ${PYPKGPREFIX}-tqdm>=4.28.1:../../misc/py-tqdm
DEPENDS+=   ${PYPKGPREFIX}-deprecation:../../devel/py-deprecation
DEPENDS+=   ${PYPKGPREFIX}-astroid:../../devel/py-astroid
DEPENDS+=   ${PYPKGPREFIX}-pygments:../../textproc/py-pygments
DEPENDS+=   ${PYPKGPREFIX}-future:../../devel/py-future
DEPENDS+=   ${PYPKGPREFIX}-pylint:../../wip/py-pylint
DEPENDS+=   ${PYPKGPREFIX}-distro-1.1.0:../../wip/py-distro
DEPENDS+=   ${PYPKGPREFIX}-node-semver:../../wip/py-node-semver
DEPENDS+=   ${PYPKGPREFIX}-fasteners:../../devel/py-fasteners
DEPENDS+=   ${PYPKGPREFIX}-patch-1.16:../../wip/py-patch
DEPENDS+=   ${PYPKGPREFIX}-colorama:../../comms/py-colorama
DEPENDS+=   ${PYPKGPREFIX}-requests:../../devel/py-requests
DEPENDS+=   ${PYPKGPREFIX}-JWT:../../textproc/py-JWT
DEPENDS+=   ${PYPKGPREFIX}-yaml:../../textproc/py-yaml
DEPENDS+=   ${PYPKGPREFIX}-sqlite3:../../databases/py-sqlite3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
