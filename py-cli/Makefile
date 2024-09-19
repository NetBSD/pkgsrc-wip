# $NetBSD$

DISTNAME=	climate-0.4.6
# py-climate is already reserved
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/mate//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=c/climate/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/lmjohns3/py-cli/
COMMENT=	Command-line utilities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-plac>=0.9.6:../../wip/py-plac

WRKSRC=		${WRKDIR}/climate-0.4.6

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
