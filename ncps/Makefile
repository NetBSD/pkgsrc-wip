# $NetBSD: Makefile,v 1.3 2004/05/02 04:48:44 blef Exp $

DISTNAME=	ncps-0.55
CATEGORIES=	sysutils
MASTER_SITES=	http://www.math.ohio-state.edu/~pschan/ncps/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.math.ohio-state.edu/~pschan/ncps/
COMMENT=	ncurses based process-killer

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_BUILDLINK3=		YES
USE_NCURSES=		YES

# It uses /proc...could be emulated, but not tested
ONLY_FOR_PLATORM=	Linux-*-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
