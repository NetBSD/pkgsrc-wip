# $NetBSD$

DISTNAME=	pymacaroons-v0.9.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/v//}
CATEGORIES=     devel python
GITHUB_PROJECT=	pymacaroons
MASTER_SITES=   ${MASTER_SITE_GITHUB:=matrix-org/}
EXTRACT_SUFX=	.zip

MAINTAINER=     kethzer.dr@gmail.com
HOMEPAGE=       https://github.com/matrix-org/
COMMENT=	Python implementation of Macaroons
LICENSE=	mit


.include "../../security/libsodium/buildlink3.mk"
.include "../../lang/python/egg.mk"

WRKSRC=		${WRKDIR}/${DISTNAME:S/v//}
USE_LANGUAGES=	# none

.include "../../mk/bsd.pkg.mk"
