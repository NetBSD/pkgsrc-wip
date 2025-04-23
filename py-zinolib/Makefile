# $NetBSD$

DISTNAME=	zinolib-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	zinolib

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/zinolib
COMMENT=	Library to connect to zino command and notification channels
LICENSE=	apache-2.0

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.0:../../devel/py-pydantic
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

# Workaround for using github tarball:
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION}

PYTHON_VERSIONS_INCOMPATIBLE+=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
