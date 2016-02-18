# $NetBSD$

DISTNAME=	ruamel.yaml-0.10.23
PKGNAME=	${PYPKGPREFIX}-ruamel-yaml-0.10.23
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=r/ruamel.yaml/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://bitbucket.org/ruamel/yaml
COMMENT=	YAML parser/emitter
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-ruamel-base>=1.0.0:../../wip/py-ruamel-base
DEPENDS+=	${PYPKGPREFIX}-ruamel-ordereddict>=0.4.9:../../wip/py-ruamel-ordereddict

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
