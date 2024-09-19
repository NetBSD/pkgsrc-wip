# $NetBSD: Makefile,v 1.2 2012/10/07 13:57:27 asau Exp $

DISTNAME=	Pweave-0.20.1
PKGNAME=	${PYPKGPREFIX}-pweave-0.20.1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pweave/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://mpastell.com/pweave
COMMENT=	Scientific reports with embedded python computations
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

WRKSRC=		${WRKDIR}/Pweave-0.20.1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
