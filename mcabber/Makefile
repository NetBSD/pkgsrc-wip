# $NetBSD: Makefile,v 1.16 2012/03/18 19:07:47 zul_ Exp $
#

DISTNAME=	mcabber-0.10.1
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
LICENSE=		gnu-gpl-v2


INSTALLATION_DIRS+= 	share/examples/mcabber
post-install:
	${INSTALL_DATA} ${WRKSRC}/mcabberrc.example \
			${DESTDIR}${PREFIX}/share/examples/mcabber

CONFIGURE_ARGS+=	--disable-hgcset

.include "options.mk"


.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
