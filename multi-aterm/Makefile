# $NetBSD: Makefile,v 1.1.1.1 2003/05/22 12:19:50 xtraeme Exp $
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

.include "../../mk/bsd.pkg.mk"
