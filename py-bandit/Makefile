# $NetBSD$

DISTNAME=	bandit-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bandit/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://wiki.openstack.org/wiki/Security/Projects/Bandit
COMMENT=	Security oriented static analyser for python code
LICENSE=	apache-2.0

DEPENDS+=       ${PYPKGPREFIX}-pbr>=1.3.0:../../devel/py-pbr
DEPENDS+=       ${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=       ${PYPKGPREFIX}-yaml>=3.1.0:../../textproc/py-yaml
DEPENDS+=       ${PYPKGPREFIX}-appdirs>=1.4.0:../../wip/py-appdirs
DEPENDS+=       ${PYPKGPREFIX}-stevedore>=1.7.0:../../wip/py-stevedore

USE_LANGUAGES=	# none

USE_LANGUAGES=	c

#EGDIR=			${PREFIX}/share/bandit/wordlist
#CONF_FILES=		${PKG_SYSCONFDIR}/bandit.yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
