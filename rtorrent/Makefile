# $NetBSD: Makefile,v 1.2 2005/05/24 10:31:24 rillig Exp $

DISTNAME=	rtorrent-0.1.4
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	Ncurses based torrent client with support for sessions

USE_LIBTOOL=		yes
USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PREFER_PKGSRC=		ncurses

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rtorrent
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/rtorrent

.include "../../wip/libtorrent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
