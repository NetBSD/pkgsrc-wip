# $NetBSD: Makefile,v 1.2 2012/10/01 21:57:43 asau Exp $
#

DISTNAME=	KtJet-1.08
PKGNAME=	ktjet-1.08
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/ktjet/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/ktjet/
COMMENT=	C++ implementation of the K clustering algorithm
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP=  configure

GNU_CONFIGURE=	yes
USE_LIBTOOL= yes
USE_LANGUAGES=	c c++

.include "../../wip/clhep/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
