# $NetBSD$

DISTNAME=	curitz-1.0.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Uninett/}
GITHUB_PROJECT=	curitz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://github.com/Uninett/curitz
COMMENT=	curses-based client to interact with zino
LICENSE=	apache-2.0

.include "../../lang/python/pyversion.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-zinolib>=1.3.4:../../wip/py-zinolib
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

# Workaround for using github tarball:
MAKE_ENV+=	SETUPTOOLS_SCM_PRETEND_VERSION=${PKGVERSION}

PYTHON_VERSIONS_INCOMPATIBLE+=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
