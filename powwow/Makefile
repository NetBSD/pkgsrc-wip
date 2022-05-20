# $NetBSD: Makefile,v 1.16 2012/10/06 11:54:50 asau Exp $

DISTNAME=	powwow-1.2.23
CATEGORIES=	games
MASTER_SITES=	https://www.hoopajoo.net/static/projects/

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	http://hoopajoo.net/projects/powwow.html
COMMENT=	Client to play MUDs
LICENSE=	gnu-gpl-v2
USE_TOOLS+=	gmake

CFLAGS+=		-D_XOPEN_SOURCE=700 -D_NETBSD_SOURCE
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-bsd

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
