# $NetBSD: Makefile,v 1.3 2003/05/23 16:39:09 xtraeme Exp $
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
			--enable-fading

BUILD_DEFS+=    ATERM_USE_KANJI ATERM_USE_XTERM_SCROLL
BUILD_DEFS+=    ATERM_USE_BIG5 ATERM_USE_GREEK

.include "../../mk/bsd.prefs.mk"

.if defined(ATERM_USE_XTERM_SCROLL) && ${ATERM_USE_XTERM_SCROLL} != NO
CONFIGUE_ARGS+=--enable-xterm-scroll
.endif

.if defined(ATERM_USE_KANJI) && ${ATERM_USE_KANJI} != NO
CONFIGURE_ARGS+=--enable-kanji
.endif

.if defined(ATERM_USE_BIG5) && ${ATERM_USE_BIG5} != NO
CONFIGURE_ARGS+=--enable-big5
.endif

.if defined(ATERM_USE_GREEK) && ${ATERM_USE_GREEK} != NO
CONFIGURE_ARGS+=--enable-greek
.endif

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
