# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:26 othyro Exp $
#

DISTNAME=		lirc-0.9.0
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lirc/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.lirc.org/
COMMENT=		Linux Infrared Remote Control

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-driver=all

#ONLY_FOR_PLATFORM=Linux-*-*

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
