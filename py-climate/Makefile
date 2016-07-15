# $NetBSD$

DISTNAME=	climate-0.4.6
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://pypi.python.org/packages/6a/da/cc87a4d6c5bc6099a6c16b3b8eda49528e6eb9c039a2c6b45513a1d19990/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/lmjohns3/py-cli/
COMMENT=	Command-line utilities
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-plac>=0.9.6:../../wip/py-plac

WRKSRC=		${WRKDIR}/climate-0.4.6

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
