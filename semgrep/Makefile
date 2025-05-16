# $NetBSD$

DISTNAME=	semgrep-0.111.1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semgrep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/returntocorp/semgrep
COMMENT=	Syntax-aware semantic code pattern search for many languages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=21.3:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-boltons>=21.0:../../devel/py-boltons
DEPENDS+=	${PYPKGPREFIX}-click>=8.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-option-group>=0.5:../../devel/py-click-option-group
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-glom>=0.4.0:../../wip/py-glom
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.6:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-lsp-jsonrpc>=1.0.0:../../textproc/py-lsp-jsonrpc
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-peewee>=3.14:../../databases/py-peewee
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.16.0:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.46:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.2:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.26:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-wcmatch>=8.3:../../textproc/py-wcmatch
DEPENDS+=	semgrep-core-${PKGVERSION_NOREV}{,nb[0-9]*}:../../wip/semgrep-core

# Avoid to install binaries
MAKE_ENV+=	SEMGREP_SKIP_BIN=yes

SUBST_CLASSES+=			setuppyversions
SUBST_STAGE.setuppyversions=	pre-configure
SUBST_MESSAGE.setuppyversions=	Avoid too strict version requirements
SUBST_FILES.setuppyversions=	setup.py
SUBST_SED.setuppyversions+=	-E -e '/~=[0-9.]+",/ s/~=/>=/g'

USE_LANGUAGES=	# none

# Only for Python >= 3.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

# Do not install tests
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/tests

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
