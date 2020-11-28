# $NetBSD$

GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	secretstorage-3.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_GITHUB:=mitya57/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/mitya57/secretstorage/
COMMENT=	Module for securely storing passwords and secrets
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-jeepney>=0.5.0:../../wip/py-jeepney

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/${DISTNAME} # Why is this necessary?

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
