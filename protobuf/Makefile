# $NetBSD: Makefile,v 1.3 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=	protobuf-2.4.1
CATEGORIES=	devel
MASTER_SITES=	http://protobuf.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://protobuf.googlecode.com/
COMMENT=	An rpc definition to source compiler by google
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	protobuf-lite.pc.in
PKGCONFIG_OVERRIDE+=	protobuf.pc.in

.include "../../mk/bsd.pkg.mk"
