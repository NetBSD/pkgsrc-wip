# $NetBSD: Makefile,v 1.1 2015/04/19 17:56:54 realzhtw Exp $

DISTNAME=	proplib-0.6.3
CATEGORIES=	devel
MASTER_SITES=	http://portableproplib.googlecode.com/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	root@zta.lk
HOMEPAGE=	http://code.google.com/p/portableproplib/
COMMENT=	Portable Property container object library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	proplib.pc.in

.include "../../mk/bsd.pkg.mk"
