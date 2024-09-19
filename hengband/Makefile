# $NetBSD: Makefile,v 1.2 2012/09/29 17:05:55 asau Exp $
#

DISTNAME=	hengband-1.6.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=hengband/10331/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://hengband.sourceforge.jp/en/index.html
COMMENT=	Variant of ZAngband 2.2.8


GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-setgid=games
CONFIGURE_ARGS+=	--with-libpath=${PREFIX}/share/hengband/

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
