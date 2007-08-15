# $NetBSD: Makefile,v 1.3 2007/08/15 22:07:31 shindenmorr Exp $
#

DISTNAME=	ekg2-0.1
CATEGORIES=	chat
MASTER_SITES=	http://pl.ekg2.org/ \
		http://pl.ekg2.org/archive/

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

WRKSRC=		${WRKDIR}/ekg2-20070303/

.include "options.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
