# $NetBSD$

DISTNAME=	reuse-tool-4.0.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fsfe/}
GITHUB_PROJECT=	reuse-tool
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://reuse.readthedocs.io/en/stable/
COMMENT=	Tool for compliance with the REUSE recommendations
LICENSE=	apache-2.0 AND gnu-gpl-v3 AND cc-by-sa-v4.0 AND cc0-1.0-universal

USE_LANGUAGES=	# none

TOOL_DEPENDS+=	${PYPKGPREFIX}-myst-parser>=3.0.1:../../textproc/py-myst-parser
TOOL_DEPENDS+=	${PYPKGPREFIX}-pbr>=6.0.0:../../devel/py-pbr
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=1.9.0:../../devel/py-poetry-core
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.3.7:../../textproc/py-sphinx
TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-apidoc>=0.5.0:../../wip/py-sphinxcontrib-apidoc
DEPENDS+=	${PYPKGPREFIX}-attrs>=21.3:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-binaryornot>=0.4.4:../../devel/py-binaryornot
DEPENDS+=	${PYPKGPREFIX}-debian>=0.1.34<0.1.45:../../wip/py-debian
DEPENDS+=	${PYPKGPREFIX}-boolean.py>=3.8.0:../../devel/py-boolean.py
DEPENDS+=	${PYPKGPREFIX}-license-expression>=1.0:../../devel/py-license-expression
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.8:../../textproc/py-tomlkit

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-build:
	cd ${WRKSRC}/docs && env ${MAKE_ENV} sphinx-build-${PYVERSSUFFIX} -b man "." "_build"

post-install:
	for manpage in \
		reuse reuse-annotate reuse-convert-dep5 reuse-download reuse-lint reuse-spdx reuse-supported-licenses ; \
	do \
		${INSTALL_MAN} ${WRKSRC}/docs/_build/$${manpage}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ ; \
	done

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
