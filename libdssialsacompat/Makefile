# $NetBSD: Makefile,v 1.1.1.1 2007/01/16 17:54:53 netcap Exp $
#

DISTNAME=	libdssialsacompat-1.0.8a
CATEGORIES=	audio
MASTER_SITES=	http://home.jps.net/~musound/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://home.jps.net/~musound/
COMMENT=	Alsa compatibility library to build DSSI

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+= c

PKGCONFIG_OVERRIDE+=	libdssialsacompat.pc.in

pre-install:
	${INSTALL_LIB_DIR} ${PREFIX}/include/dssi/alsa/sound

.include "../../mk/bsd.pkg.mk"
