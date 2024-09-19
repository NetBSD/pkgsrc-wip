# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:04 othyro Exp $
#

DISTNAME=	ExHuME-1.3.5
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/exhume/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/exhume/
COMMENT=	Monte Carlo simulation of central exclusive production
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ fortran

.include "../../wip/clhep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
