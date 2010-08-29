# $NetBSD: Makefile,v 1.3 2010/08/29 12:49:44 cheusov Exp $
#

DISTNAME=		lirc-0.8.0
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lirc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.lirc.org/
COMMENT=		Linux Infrared Remote Control

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-driver=all

ONLY_FOR_PLATFORM=Linux-*-*

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
