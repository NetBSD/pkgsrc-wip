# $NetBSD: Makefile,v 1.5 2012/11/05 13:00:12 othyro Exp $
#

DISTNAME=	libdssialsacompat-1.0.8a
CATEGORIES=	audio
MASTER_SITES=	http://smbolton.com/linux/

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://smbolton.com/linux.html
COMMENT=	Alsa compatibility library to build DSSI
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c

INSTALLATION_DIRS=	include/dssi/alsa/sound
PKGCONFIG_OVERRIDE+=	libdssialsacompat.pc.in

.include "../../mk/bsd.pkg.mk"
