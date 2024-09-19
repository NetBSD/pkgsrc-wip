# $NetBSD$

DISTNAME=	anyconfig-0.9.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/anyconfig/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/anyconfig/
COMMENT=	APIs to load and dump configuration files in various formats
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-yaml>=5.3.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.2:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.16.12:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.17.2:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-jmespath>=0.10.0:../../textproc/py-jmespath
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10.1:../../textproc/py-toml

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	setup.py
SUBST_SED.paths=	-e 's,share/man/man1,${PREFIX}/man/man1,g'
SUUBST_VARS.paths=	PREFIX

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
