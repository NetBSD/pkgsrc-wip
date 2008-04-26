# $NetBSD: Makefile,v 1.10 2008/04/26 12:28:53 zul_ Exp $

DISTNAME=		mcabber-0.9.7
CATEGORIES=		chat
MASTER_SITES=		http://www.lilotux.net/~mikael/mcabber/files/
EXTRACT_SUFX=		.tar.bz2


MAINTAINER=		degroote@NetBSD.org
HOMEPAGE=		http://www.lilotux.net/~mikael/mcabber/
COMMENT=		Jabber console client

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake xgettext pkg-config
USE_NCURSES=		yes
USE_DIRS+=		xdg-1.4

post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabber.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mcabber
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example ${PREFIX}/share/examples/mcabber/mcabberrc

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
