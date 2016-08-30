# $NetBSD$

DISTNAME=	pafy-0.3.74
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pafy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://np1.github.io/pafy/
COMMENT=	Retrieve YouTube content and metadata
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/scripts/ytdl ${WRKSRC}/scripts/ytdl${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
