# $NetBSD: Makefile,v 1.3 2004/05/01 05:29:58 blef Exp $
#

DISTNAME=		terminus-font-4.06
CATEGORIES=		fonts
MASTER_SITES=		http://www.is-vn.bg/hamster/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.is-vn.bg/hamster/jimmy-en.html
COMMENT=		Clean fixed width font

USE_BUILDLINK3=		yes

USE_X11BASE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/lib/X11/fonts/misc

FONTS_X11_DIRS=         ${PREFIX}/lib/X11/fonts/misc

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
