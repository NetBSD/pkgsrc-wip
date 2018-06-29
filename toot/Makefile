# $NetBSD$

DISTNAME=	toot-0.19.0
CATEGORIES=	chat www
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot/}

MAINTAINER=	nia.alarie@gmail.com
HOMEPAGE=	https://github.com/ihabunek/toot
COMMENT=	Command line client for the Mastodon social network API
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-cursespanel-[0-9]*:../../devel/py-cursespanel
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
