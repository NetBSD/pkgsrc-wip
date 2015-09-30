# $NetBSD: Makefile,v 1.1 2015/06/16 08:29:23 ahp-nils Exp $

DISTNAME=	binaryornot-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/audreyr/binaryornot/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}
EXTRACT_SUFX=	.zip

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/audreyr/binaryornot/
COMMENT=	Guess whether a file is binary or text
LICENSE=	modified-bsd

USE_LANGUAGES=	#none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
