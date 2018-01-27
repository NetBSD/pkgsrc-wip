# $NetBSD$

DISTNAME=	matrix-angular-sdk-0.6.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
GITHUB_PROJECT=	matrix-angular-sdk
MASTER_SITES=	${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	AngularJS services for implementing the Client-Server API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=		# none
WRKSRC=			${WRKDIR}/${DISTNAME}
INSTALLATION_DIRS=	${PYSITELIB}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
