# $NetBSD: Makefile,v 1.1.1.1 2003/10/30 01:29:09 xtraeme Exp $
#

DISTNAME=	xwpe-1.5.29a
CATEGORIES=	editors
MASTER_SITES=	http://www.identicalsoftware.com/xwpe/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_NCURSES=		# tigetstr()
USE_X11=		yes

ALL_TARGET=		# defined

.include "../../devel/ncurses/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
