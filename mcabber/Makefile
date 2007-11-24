# $NetBSD: Makefile,v 1.7 2007/11/24 15:55:56 netcap Exp $

DISTNAME=		mcabber-0.9.5
CATEGORIES=		chat
MASTER_SITES=		http://www.lilotux.net/~mikael/mcabber/files/
EXTRACT_SUFX=		.tar.bz2


MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://www.lilotux.net/~mikael/mcabber/
COMMENT=		Jabber console client

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake xgettext pkg-config
USE_NCURSES=		yes
USE_DIRS+=		xdg-1.4

# Does this still make sense with ncursesw?
#Work in Progress for UTF-8 issue.
#CONFIGURE_ENV+= CFLAGS=${CFLAGS:M*:Q} CPPFLAGS=${CPPFLAGS:M*:Q}
#CFLAGS+=        -I${LOCALBASE}/include
#CPPFLAGS=       ${CFLAGS}
#LDFLAGS+=       -lcrypto -L${LOCALBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabber.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mcabber
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${PREFIX}/share/examples/mcabber/mcabberrc

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
