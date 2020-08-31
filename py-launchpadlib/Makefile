# $NetBSD$

DISTNAME=	launchpadlib-1.10.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/launchpadlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/launchpadlib/
		# https://help.launchpad.net/API/launchpadlib
COMMENT=	Script Launchpad through its web services interfaces
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
# These are in wip/ not in pkgsrc proper:
DEPENDS+=	${PYPKGPREFIX}-wadllib-[0-9]*:../../wip/py-wadllib
DEPENDS+=	${PYPKGPREFIX}-lazr.uri-[0-9]*:../../wip/py-lazr.uri
DEPENDS+=	${PYPKGPREFIX}-lazr.restfulclient-[0-9]*:../../wip/py-lazr.restfulclient

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-keyring

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
