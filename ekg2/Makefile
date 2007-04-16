# $NetBSD: Makefile,v 1.1.1.1 2007/04/16 19:00:24 shindenmorr Exp $
#

DISTNAME=	ekg2-20070101
CATEGORIES=	chat
MASTER_SITES=	http://pl.ekg2.org/archive/

MAINTAINER=	shinden@linux.pl
HOMEPAGE=	http://pl.ekg2.org/
COMMENT=	Multi-protocol communicator - gg, jabber, irc

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_NCURSES=		yes
USE_TOOLS+=		perl
CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--enable-dynamic \
			--without-inotify \
			--without-ioctld \
			--with-expat \
			--without-gtk \
			--without-readline \
			--disable-nls \
			--without-libxosd \
			--without-perl \
			--without-python \
			--with-sqlite3 \
			--without-gpg \
			--without-logsoracle \
			--with-curses=${BUILDLINK_PREFIX.ncurses}

.include "options.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
