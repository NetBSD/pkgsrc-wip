# $NetBSD: Makefile,v 1.9 2010/03/03 10:16:40 shindenmorr Exp $
#

DISTNAME=	ekg2-20091123
CATEGORIES=	chat
MASTER_SITES=	http://pl.ekg2.org/
MASTER_SITES+=	http://pl.ekg2.org/archive/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://pl.ekg2.org/
COMMENT=	Multiplatform, multiprotocol, plugin-based instant messanger
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

PKG_DESTDIR_SUPPORT=	destdir
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_NCURSES=		yes
USE_TOOLS+=		perl gmake
CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--enable-dynamic \
			--without-inotify \
			--without-ioctld \
			--without-gtk \
			--without-readline \
			--disable-nls \
			--without-libxosd \
			--without-perl \
			--without-python \
			--with-sqlite3 \
			--without-gpg \
			--without-logsoracle \
			--with-ncurses=${BUILDLINK_PREFIX.ncurses}

.include "options.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
