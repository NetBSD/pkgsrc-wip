# $NetBSD$

DISTNAME=	semgrep-0.35.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semgrep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/returntocorp/semgrep
COMMENT=	Syntax-aware semantic code pattern search for many languages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=19.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-junit-xml2>=1.9:../../wip/py-junit-xml2
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.16.10:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.46.1:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3:../../textproc/py-yaml

# Avoid to install binaries
INSTALL_ENV+=	HOMEBREW_SYSTEM=yes

USE_LANGUAGES=	# none

# Only for Python >= 3.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
