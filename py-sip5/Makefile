# $NetBSD$

DISTNAME=	sip-${PKGVERSION_NOREV}
PKGNAME=        ${PYPKGPREFIX}-sip5-5.5.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sip/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	https://pypi.org/project/sip/
COMMENT=	Tool to create Python bindings for C++ libraries
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3 OR modified-bsd


DEPENDS+=	${PYPKGPREFIX}-packaging>=0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-toml>=0:../../textproc/py-toml

USE_LANGUAGES=	c c++

CLI=			build distinfo install module sdist wheel
MODULE.build=		sipbuild.tools.build
MODULE.distinfo=	sipbuild.distinfo.main
MODULE.install=		sipbuild.tools.install
MODULE.module=		sipbuild.module.main
MODULE.sdist=		sipbuild.tools.sdist
MODULE.wheel=		sipbuild.tools.wheel

post-install:
.for cli in ${CLI}
	{ echo "#!${PYTHONBIN}"; \
	  echo "import sys"; \
	  echo "from ${MODULE.${cli}} import main; sys.exit(main());"; \
	} > ${DESTDIR}${PREFIX}/bin/sip-${cli}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
