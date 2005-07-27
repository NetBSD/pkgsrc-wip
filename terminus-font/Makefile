# $NetBSD: Makefile,v 1.5 2005/07/27 16:31:07 thomasklausner Exp $
#

DISTNAME=		terminus-font-4.06
CATEGORIES=		fonts
MASTER_SITES=		http://www.is-vn.bg/hamster/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.is-vn.bg/hamster/jimmy-en.html
COMMENT=		Clean fixed width font


USE_X11BASE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/lib/X11/fonts/misc

FONTS_X11_DIRS=         ${PREFIX}/lib/X11/fonts/misc

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
