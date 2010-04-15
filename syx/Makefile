# $NetBSD: Makefile,v 1.2 2010/04/15 07:10:07 athaba Exp $
#

DISTNAME=	syx-0.1.7
CATEGORIES=	lang devel
MASTER_SITES=	http://syx.berlios.de/downloads/

MAINTAINER=	athaba@users.sourceforge.net
HOMEPAGE=	http://syx.berlios.de/
COMMENT=	Free and portable smalltalk implementation
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
INFO_FILES=	yes

CONFIGURE_ARGS=	--enable-maintainer-mode \
		--with-gmp \
		--disable-gtk \
		--disable-readline \
		--disable-x11

TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	syx.pc.in

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "options.mk"
.include "../../mk/bsd.pkg.mk"
