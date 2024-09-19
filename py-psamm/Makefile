# $NetBSD$

DISTNAME=	psamm-0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/psamm/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/zhanglab/psamm
COMMENT=	PSAMM metabolic modeling tools
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-six>=1.10.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

WRKSRC=		${WRKDIR}/psamm-0.18

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
