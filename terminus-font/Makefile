# $NetBSD: Makefile,v 1.8 2006/05/19 16:51:40 ykomatsu Exp $
#

DISTNAME=		terminus-font-4.16
CATEGORIES=		fonts
MASTER_SITES=		http://www.is-vn.bg/hamster/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.is-vn.bg/hamster/jimmy-en.html
COMMENT=		Clean fixed width font

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/lib/X11/fonts/misc

FONTS_DIRS.x11=		${PREFIX}/lib/X11/fonts/misc
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/misc

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
