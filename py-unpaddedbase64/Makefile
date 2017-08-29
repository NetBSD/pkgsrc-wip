# $NetBSD$

DISTNAME=	unpaddedbase64-v1.1.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/v//}
CATEGORIES=    	devel python
GITHUB_PROJECT=	python-unpaddedbase64
MASTER_SITES=   ${MASTER_SITE_GITHUB:=matrix-org/}
EXTRACT_SUFX=   .zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=       https://github.com/matrix-org/
COMMENT=	Encode and decode Base64
LICENSE=        apache-2.0

USE_LANGUAGES=	# none
WRKSRC=         ${WRKDIR}/python-${DISTNAME:S/v//}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
