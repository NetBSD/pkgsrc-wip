# $NetBSD: Makefile,v 1.1.1.1 2011/05/09 20:15:34 jihbed Exp $
#

DISTNAME=	ExHuME-1.3.5
PKGNAME=	exhume-1.3.5
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/exhume/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/exhume/
COMMENT=	Monte Carlo simulation of central exclusive production
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ fortran

.include "../../wip/clhep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
