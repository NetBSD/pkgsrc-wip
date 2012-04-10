# $NetBSD: Makefile,v 1.2 2012/04/10 02:02:13 genolopolis Exp $
#

DISTNAME=	protobuf-2.4.1
CATEGORIES=	devel
MASTER_SITES=	http://protobuf.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://protobuf.googlecode.com/
COMMENT=	An rpc definition to source compiler by google
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	protobuf-lite.pc.in
PKGCONFIG_OVERRIDE+=	protobuf.pc.in

.include "../../mk/bsd.pkg.mk"
