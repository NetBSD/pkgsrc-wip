# $NetBSD$
DISTNAME=	python-signedjson-1.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/v//:S/python-//}
CATEGORIES=	security
GITHUB_PROJECT=	python-signedjson
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Signs JSON objects with ED25519 signatures
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
