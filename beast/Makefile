# $NetBSD: Makefile,v 1.3 2004/04/12 23:17:29 lsed Exp $
#

DISTNAME=	beast-0.5.4
CATEGORIES=	audio
MASTER_SITES=	http://beast.gtk.org/beast-ftp/v0.5/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://beast.gtk.org/
COMMENT=	Bedevilled Audio System

AUTOCONF_REQD=	2.13

USE_BUILDLINK2=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

LDFLAGS+=	-lossaudio

pre-configure:
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../multimedia/libogg/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
