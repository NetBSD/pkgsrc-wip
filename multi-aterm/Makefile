# $NetBSD: Makefile,v 1.2 2003/05/22 15:01:17 xtraeme Exp $
#

DISTNAME=	multi-aterm-0.0.4
CATEGORIES=	x11
MASTER_SITES=	http://www.materm.tuxfamily.org/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.materm.tuxfamily.org/
COMMENT=	Multi-terminal for the X Window system based on aterm

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_X11=		yes

CONFIGURE_ARGS+=	--enable-mousewheel \
			--enable-swapscreen \
			--enable-keepscrolling \
			--enable-half-shadow \
			--enable-shading \
			--enable-fading \
			--enable-xterm-scroll \
			--enable-kanji \
			--enable-big5

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
