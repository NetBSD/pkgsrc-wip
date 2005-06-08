# $NetBSD: Makefile,v 1.9 2005/06/08 15:47:00 dillo Exp $
#

DISTNAME=	beast-0.5.4
CATEGORIES=	audio
MASTER_SITES=	http://beast.gtk.org/beast-ftp/v0.5/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://beast.gtk.org/
COMMENT=	Bedevilled Audio System

USE_X11=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake autoconf213
GNU_CONFIGURE=	yes

LDFLAGS+=	${LIBOSSAUDIO}

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
