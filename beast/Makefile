# $NetBSD: Makefile,v 1.4 2004/04/24 22:53:29 thomasklausner Exp $
#

DISTNAME=	beast-0.5.4
CATEGORIES=	audio
MASTER_SITES=	http://beast.gtk.org/beast-ftp/v0.5/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://beast.gtk.org/
COMMENT=	Bedevilled Audio System

AUTOCONF_REQD=	2.13

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make
GNU_CONFIGURE=	yes

LDFLAGS+=	${LIBOSSAUDIO}

pre-configure:
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/autoconf.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
