# $NetBSD$

DISTNAME=	semgrep-0.60.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/semgrep/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/returntocorp/semgrep
COMMENT=	Syntax-aware semantic code pattern search for many languages
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-attrs>=19.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging>=20.4:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-peewee>=3.14.4:../../databases/py-peewee
DEPENDS+=	${PYPKGPREFIX}-requests>=2.22.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.16.10:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.46.1:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-wcmatch>=8.2:../../textproc/py-wcmatch
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3:../../textproc/py-yaml
DEPENDS+=	semgrep-core-${PKGVERSION_NOREV}{,nb[0-9]*}:../../wip/semgrep-core

# Avoid to install binaries
MAKE_ENV+=	SEMGREP_SKIP_BIN=yes

USE_LANGUAGES=	# none

# Only for Python >= 3.6
PYTHON_VERSIONS_INCOMPATIBLE=	27

# Do not install tests
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/${PYSITELIB}/tests

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
