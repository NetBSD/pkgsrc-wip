# $NetBSD: Makefile,v 1.5 2005/05/24 10:31:12 rillig Exp $

DISTNAME=	ncps-0.55
CATEGORIES=	sysutils
MASTER_SITES=	http://www.math.ohio-state.edu/~pschan/ncps/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.math.ohio-state.edu/~pschan/ncps/
COMMENT=	ncurses based process-killer

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_NCURSES=		YES

# It uses /proc...could be emulated, but not tested
ONLY_FOR_PLATORM=	Linux-*-*

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
