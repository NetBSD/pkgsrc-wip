# $NetBSD: Makefile,v 1.4 2015/07/07 18:09:04 leot1990 Exp $

DISTNAME=	zbar-0.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zbar/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://zbar.sourceforge.net/
COMMENT=	Bar code reader
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c

# XXX: should we move some of them to options.mk?
CONFIGURE_ARGS+=	--disable-video
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-python
CONFIGURE_ARGS+=	--without-qt

PKGCONFIG_OVERRIDE+=	zbar-gtk.pc.in
PKGCONFIG_OVERRIDE+=	zbar-qt.pc.in
PKGCONFIG_OVERRIDE+=	zbar.pc.in

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
TEST_TARGET=	check
USE_LANGUAGES=	c c++
.endif

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
