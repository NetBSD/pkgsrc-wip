# $NetBSD: Makefile,v 1.2 2004/01/25 02:11:34 grantbeattie Exp $
#

DISTNAME=		beast-0.5.4
CATEGORIES=		audio
MASTER_SITES=		http://beast.gtk.org/beast-ftp/v0.5/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://beast.gtk.org/
COMMENT=		Bedevilled Audio System

LDFLAGS+=		-lossaudio
USE_X11=		yes
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
AUTOCONF_REQD=          2.13

pre-configure:
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../audio/libogg/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
