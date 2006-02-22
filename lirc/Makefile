# $NetBSD: Makefile,v 1.1.1.1 2006/02/22 15:56:09 poppnk Exp $
#

DISTNAME=		lirc-0.8.0
CATEGORIES=		wip comms linux
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lirc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://lirc.sourceforge.net/
COMMENT=		Linux Infrared Remote Control

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-driver=all

ONLY_FOR_PLATFORM=Linux-*-*

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
