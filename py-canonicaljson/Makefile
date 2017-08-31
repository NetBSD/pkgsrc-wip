# $NetBSD$

DISTNAME=	canonicaljson-1.0.0
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
GITHUB_PROJECT=	python-canonicaljson
MASTER_SITES=   ${MASTER_SITE_GITHUB:=matrix-org/}
GITHUB_TAG=     v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=       https://github.com/matrix-org/
COMMENT=	Encodes objects and arrays
LICENSE=        apache-2.0


INSTALLATION_DIRS=     ${PYSITELIB}

WRKSRC=         ${WRKDIR}/python-${DISTNAME}
USE_LANGUAGES=	python

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
