# $NetBSD: Makefile,v 1.7 2015/07/04 02:41:41 jihbed Exp $

DISTNAME=	smmap2-2.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/smmap2/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://github.com/Byron/smmap
COMMENT=	Git implementation of a sliding window memory map manager
LICENSE=	modified-bsd

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]*:../../devel/py-nose
BUILD_DEPENDS+=	${PYPKGPREFIX}-nosexcover-[0-9]*:../../devel/py-nosexcover
BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage>=3.4:../../devel/py-coverage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
