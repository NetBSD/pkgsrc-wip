# $NetBSD$

DISTNAME=	fedmsg-0.16.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fedmsg/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/fedora-infra/fedmsg/
COMMENT=	Fedora Messaging Client API
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-requests>=2.5.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-zmq>=14.4.1:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-psutil>=2.1.3:../../sysutils/py-psutil
#DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.0.1:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.4.2:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-kitchen>=1.2.1:../../wip/py-kitchen
DEPENDS+=	${PYPKGPREFIX}-moksha-hub>=1.4.4:../../wip/py-moksha-hub

USE_TOOLS+=	bash
USE_LANGUAGES=	# none

REPLACE_BASH+=	fedmsg/tests/test_certs/rebuild-all-fedmsg-certs

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-moksha-common via py-moksha-hub

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
