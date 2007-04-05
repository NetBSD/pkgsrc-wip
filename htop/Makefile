# $NetBSD: Makefile,v 1.2 2007/04/05 23:31:37 alchow Exp $
#

DISTNAME=	htop-0.6.5
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htop/}

MAINTAINER=	alchow@users.sourceforge.net
HOMEPAGE=	http://htop.sourceforge.net/
COMMENT=	Interactive process viewer for Linux

ONLY_FOR_PLATFORM=      Linux-*-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${DESTDIR}${PREFIX}/share/htop

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
