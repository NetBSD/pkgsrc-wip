# $NetBSD: Makefile,v 1.1.1.1 2003/12/26 21:09:23 mpasternak Exp $
#

DISTNAME=		terminus-font-4.06
CATEGORIES=		fonts
MASTER_SITES=		http://www.is-vn.bg/hamster/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.is-vn.bg/hamster/jimmy-en.html
COMMENT=		Terminus Font - a clean fixed width font

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${X11BASE}/lib/X11/fonts/misc

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
