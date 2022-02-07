# $NetBSD: Makefile,v 1.11 2022/01/04 20:55:06 wiz Exp $

DISTNAME=	sphinx-theme-builder-0.2.0a13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/a/alpha/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sphinx-theme-builder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/sphinx-theme-builder/#files
COMMENT=	Tool for authoring Sphinx themes with a simple workflow
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-rich-[0-9]*:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
DEPENDS+=	${PYPKGPREFIX}-nodeenv-[0-9]*:../../wip/py-nodeenv
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pep621-[0-9]*:../../devel/py-pep621

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/stb ${DESTDIR}${PREFIX}/bin/stb-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
