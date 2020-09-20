# $NetBSD$

DISTNAME=	property-manager-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	https://files.pythonhosted.org/packages/2a/fd/5711b49f570916e166ba3e7f7205d43b0fb94b4c3e842545c7be8c6efe32/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://property-manager.readthedocs.io
COMMENT=	Useful property variants for Python programming
LICENSE=	mit

DEPENDS+=	#${PYPKGPREFIX}-humanfriendly>=8.0:../../wip/py-humanfriendly
DEPENDS+=	#${PYPKGPREFIX}-verboselogs>=1.1:../../wip/py-verboselogs

TEST_DEPENDS+=	${PYPKGPREFIX}-coloredlogs>=5.0:../../wip/py-coloredlogs


USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
