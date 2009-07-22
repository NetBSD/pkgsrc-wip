# $NetBSD: Makefile,v 1.13 2009/07/22 09:53:13 thomasklausner Exp $
#

DISTNAME=	mcabber-0.9.9
CATEGORIES=	chat
MASTER_SITES=	http://www.lilotux.net/~mikael/mcabber/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		degroote@NetBSD.org
HOMEPAGE=		http://www.lilotux.net/~mikael/mcabber/
COMMENT=		Jabber console client

PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_PORTABILITY_SKIP+=	contrib/events/eventcmd.pastebin

GNU_CONFIGURE=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake xgettext pkg-config
USE_NCURSES=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabber.desktop ${PREFIX}/share/applications/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mcabber
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example \
			${DESTDIR}${PREFIX}/share/examples/mcabber

CONFIGURE_ARGS+=	--disable-hgcset

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
