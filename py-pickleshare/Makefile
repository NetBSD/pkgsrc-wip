# $NetBSD$

DISTNAME=	pickleshare-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pickleshare/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/pickleshare/pickleshare
COMMENT=	Tiny shelve-like database with concurrency support
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../wip/py-six

WRKSRC=		${WRKDIR}/pickleshare-0.7.3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
