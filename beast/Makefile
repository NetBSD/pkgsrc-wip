# $NetBSD: Makefile,v 1.16 2012/06/13 09:26:33 othyro Exp $
#

DISTNAME=	beast-0.5.4
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://beast.gtk.org/beast-ftp/v0.5/

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	http://beast.gtk.org/
COMMENT=	Bedevilled Audio System
LICENSE=	gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake autoconf213 autoconf
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

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
