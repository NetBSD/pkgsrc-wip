# $NetBSD: Makefile,v 1.2 2012/09/29 17:05:55 asau Exp $
#

DISTNAME=	HepMCVisual-1.1.6
PKGNAME=	hepmcvisual-1.1.6
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/hepmcvisual/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/hepmcvisual/
COMMENT=	Interactive Browser for HepMC events 
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/HepMCVisual

CHECK_PORTABILITY_SKIP= configure

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
