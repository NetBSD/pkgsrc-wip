# $NetBSD$

DISTNAME=	pynetbox-7.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pynetbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/netbox-community/pynetbox
COMMENT=	Python API client library for NetBox
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>2.20.0<3.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-packaging<24.0:../../devel/py-packaging
# also needs unpackaged docker_ip
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
