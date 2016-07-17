# $NetBSD$

DISTNAME=	hepcrawl-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	https://pypi.python.org/packages/17/db/3e0933de5e5547394928f3d76cbd655e11cd8b7f933c6658e8a109f5ff1c/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/inspirehep/hepcrawl
COMMENT=	Scrapy project for feeds into INSPIRE-HEP
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-furl>=0.4.5:../../www/py-furl

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
