# $NetBSD: Makefile,v 1.1 2012/11/09 18:14:45 jihbed Exp $
#

DISTNAME=	zipline-0.5.1
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zipline/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://github.com/quantopian/zipline
COMMENT=	Backtester for financial algorithms
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/zipline-0.5.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
