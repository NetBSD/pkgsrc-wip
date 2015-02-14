# $NetBSD: Makefile,v 1.1 2015/02/14 10:58:25 jihbed Exp $

DISTNAME=	Pafy-0.3.72
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/p/pafy/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://np1.github.io/pafy/
COMMENT=	Retrieve YouTube content and metadata
LICENSE=	gnu-lgpl-v3

WRKSRC=		${WRKDIR}/Pafy-0.3.72

USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/scripts/ytdl ${WRKSRC}/scripts/ytdl${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
