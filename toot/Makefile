# $NetBSD$

DISTNAME=	toot-0.18.0
CATEGORIES=	chat www
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://github.com/ihabunek/toot
COMMENT=	Mastodon CLI client
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
