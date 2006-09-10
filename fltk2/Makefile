# $NetBSD: Makefile,v 1.1.1.1 2006/09/10 23:13:27 milosn Exp $

FLTK_VERSION=	5425
DISTNAME=	fltk-2.0.x-r${FLTK_VERSION}
PKGNAME=	fltk2-${FLTK_VERSION}
PKGREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	http://ftp.rz.tu-bs.de/pub/mirror/ftp.easysw.com/ftp/pub/fltk/snapshots/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.fltk.org/
COMMENT=	Fast Light Tool Kit for GUI, development branch

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-threads

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
