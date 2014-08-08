# $NetBSD: Makefile,v 1.1 2014/08/08 11:56:44 chybz Exp $

DISTNAME=	nanomsg-0.4-beta
PKGNAME=	nanomsg-0.4beta
CATEGORIES=	devel
MASTER_SITES=	http://download.nanomsg.org/

MAINTAINER=	rchibois@gmail.com
HOMEPAGE=	http://nanomsg.org/
COMMENT=	Scalability protocols library
LICENSE=	mit OR x11

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libnanomsg.pc.in

.include "../../mk/bsd.pkg.mk"
