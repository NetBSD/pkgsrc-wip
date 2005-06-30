# $NetBSD: Makefile,v 1.5 2005/06/30 11:28:30 imilh Exp $

DISTNAME=	rtorrent-0.2.6
CATEGORIES=	net
MASTER_SITES=	http://libtorrent.rakshasa.no/downloads/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://libtorrent.rakshasa.no/
COMMENT=	Ncurses based torrent client with support for sessions

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

PREFER_PKGSRC=		ncurses

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rtorrent
		${INSTALL_DATA} ${WRKSRC}/doc/rtorrent.rc \
						${PREFIX}/share/doc/rtorrent
		${INSTALL_DATA} ${WRKSRC}/doc/faq.xml \
						${PREFIX}/share/doc/rtorrent

.include "../../wip/libtorrent/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
