# $NetBSD: Makefile,v 1.1.1.1 2003/06/05 13:22:35 poppnk Exp $

DISTNAME=	ncps-0.55
CATEGORIES=	sysutils
MASTER_SITES=	http://www.math.ohio-state.edu/~pschan/ncps/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.math.ohio-state.edu/~pschan/ncps/
COMMENT=	ncurses based process-killer

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_BUILDLINK2=		YES
USE_NCURSES=		YES

# It uses /proc...could be emulated, but not tested
ONLY_FOR_PLATORM=	Linux-*-*

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
