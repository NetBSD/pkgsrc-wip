# $NetBSD$

DISTNAME=	pafy-0.5.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pafy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://np1.github.io/pafy/
COMMENT=	Retrieve YouTube content and metadata
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/ytdl ${DESTDIR}${PREFIX}/bin/ytdl${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
