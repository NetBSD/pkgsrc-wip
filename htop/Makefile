# $NetBSD: Makefile,v 1.1.1.1 2007/04/05 02:19:34 alchow Exp $
#

DISTNAME=	htop-0.6.5
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=htop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://htop.sourceforge.net/
COMMENT=	Interactive process viewer for Linux

ONLY_FOR_PLATFORM=      Linux-*-*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${DESTDIR}${PREFIX}/share/htop

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
