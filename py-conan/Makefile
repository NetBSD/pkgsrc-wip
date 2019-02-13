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

DEPENDS+=   ${PYPKGPREFIX}-pluginbase>=0.5<1.0:../../wip/py-pluginbase
DEPENDS+=   ${PYPKGPREFIX}-bottle>=0.12.8<0.13:../../www/py-bottle
DEPENDS+=   ${PYPKGPREFIX}-tqdm>=4.28.1<5:../../misc/py-tqdm
DEPENDS+=   ${PYPKGPREFIX}-deprecation>=2.0<2.1:../../devel/py-deprecation
DEPENDS+=   ${PYPKGPREFIX}-astroid>=1.6<2.0:../../devel/py-astroid
DEPENDS+=   ${PYPKGPREFIX}-pygments>=2.0<3.0:../../textproc/py-pygments
DEPENDS+=   ${PYPKGPREFIX}-future-0.16.0:../../devel/py-future
DEPENDS+=   ${PYPKGPREFIX}-pylint>=1.9.3:../../wip/py-pylint
DEPENDS+=   ${PYPKGPREFIX}-distro>=1.0.2<1.2.0:../../wip/py-distro
DEPENDS+=   ${PYPKGPREFIX}-node-semver-0.6.1:../../wip/py-node-semver
DEPENDS+=   ${PYPKGPREFIX}-fasteners>=0.14.1:../../devel/py-fasteners
DEPENDS+=   ${PYPKGPREFIX}-patch-1.16:../../wip/py-patch
DEPENDS+=   ${PYPKGPREFIX}-colorama>=0.3.3<0.5.0:../../comms/py-colorama
DEPENDS+=   ${PYPKGPREFIX}-requests>=2.7.0<3.0.0:../../devel/py-requests
DEPENDS+=   ${PYPKGPREFIX}-JWT>=1.4.0<2.0.0:../../textproc/py-JWT
DEPENDS+=   ${PYPKGPREFIX}-yaml>=3.11<3.14.0:../../textproc/py-yaml
DEPENDS+=   ${PYPKGPREFIX}-sqlite3:../../databases/py-sqlite3

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
