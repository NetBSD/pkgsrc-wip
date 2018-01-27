# $NetBSD$

DISTNAME=	unpaddedbase64-${VERSION}
VERSION=	1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
GITHUB_PROJECT=	python-unpaddedbase64
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Encode and decode Base64
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
WRKSRC=		${WRKDIR}/python-${DISTNAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
