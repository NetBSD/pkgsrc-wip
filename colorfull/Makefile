# $NetBSD: Makefile,v 1.1 2014/07/21 21:49:37 jihbed Exp $

DISTNAME=	ColorFull-0.90
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://colorfull.hepforge.org/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://colorfull.hepforge.org/
COMMENT=	ColorFull is a C++ code for calculations in QCD color space
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ColorFull-0.9

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
