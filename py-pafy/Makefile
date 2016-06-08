# $NetBSD$

DISTNAME=	pafy-0.3.74
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pafy/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://np1.github.io/pafy/
COMMENT=	Retrieve YouTube content and metadata
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/pafy-0.3.74

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/scripts/ytdl ${WRKSRC}/scripts/ytdl${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
