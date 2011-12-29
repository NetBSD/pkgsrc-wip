# $NetBSD: Makefile,v 1.1.1.1 2011/12/29 22:37:09 jihbed Exp $
#

DISTNAME=	HepMCVisual-1.1.6
PKGNAME=	hepmcvisual-1.1.6
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/hepmcvisual/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/hepmcvisual/
COMMENT=	Interactive Browser for HepMC events 
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/HepMCVisual

CHECK_PORTABILITY_SKIP= configure

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
