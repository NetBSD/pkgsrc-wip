# $NetBSD$

DISTNAME=	howdoi-1.1.11
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=h/howdoi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gleitz/howdoi
COMMENT=	Instant coding answers via the command line
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pyquery-[0-9]*:../../textproc/py-pyquery
DEPENDS+=	${PYPKGPREFIX}-requests-cache-[0-9]*:../../wip/py-requests-cache
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

USE_LANGUAGES=		# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
