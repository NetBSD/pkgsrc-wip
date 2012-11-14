# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:09 othyro Exp $
#

DISTNAME=	HepMCVisual-1.1.6
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	misc
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
