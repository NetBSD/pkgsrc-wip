# $NetBSD$

DISTNAME=	bpytop-1.0.50
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/bpytop/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/aristocratos/bpytop
COMMENT=	Stats for processor, memory, disks, network and processes
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-psutil>=5.7.0:../../sysutils/py-psutil

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
