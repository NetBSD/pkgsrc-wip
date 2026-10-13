# $NetBSD: Makefile,v 1.18 2012/11/17 11:03:23 kristerw Exp $

# 0.15.0 in 2019
# See also https://github.com/tim-janik/beast
DISTNAME=	beast-0.5.4
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	https://beast.testbit.org/pub/beast-0.15.0.tar.xz

MAINTAINER=	collver1@comcast.net
HOMEPAGE=	https://www.beast.testbit.eu/
COMMENT=	Bedevilled Audio System
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake autoconf213
GNU_CONFIGURE=	yes

LDFLAGS+=	${LIBOSSAUDIO}

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/guile18/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
