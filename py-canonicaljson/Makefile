# $NetBSD$

DISTNAME=	canonicaljson-v1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/v//}
CATEGORIES=	devel python
GITHUB_PROJECT=	python-canonicaljson
MASTER_SITES=   ${MASTER_SITE_GITHUB:=matrix-org/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=       https://github.com/matrix-org/
COMMENT=	Encodes objects and arrays
LICENSE=        apache-2.0


WRKSRC=         ${WRKDIR}/python-${DISTNAME:S/v//}
USE_LANGUAGES=	python	

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
