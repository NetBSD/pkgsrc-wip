# $NetBSD: Makefile,v 1.1 2014/07/21 22:36:07 jihbed Exp $

DISTNAME=	CheckMATE-1.1.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math python
MASTER_SITES=	https://www.hepforge.org/archive/checkmate/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://checkmate.hepforge.org/
COMMENT=	Tool to easily test simulated event files against LHC results
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/alpha

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
