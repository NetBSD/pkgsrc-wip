# $NetBSD$

DISTNAME=	pynetbox-7.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=netbox-community/}
GITHUB_PROJECT=	pynetbox
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/netbox-community/pynetbox
COMMENT=	Python API client library for NetBox
LICENSE=	apache-2.0

EGG_NAME=	${DISTNAME}

DEPENDS+=	${PYPKGPREFIX}-requests>2.20.0<3.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-packaging<24.0:../../devel/py-packaging

# Needed for installation:
#DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
#DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
#TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm->=0:../../devel/py-setuptools_scm

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm

.include "../../lang/python/extension.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
