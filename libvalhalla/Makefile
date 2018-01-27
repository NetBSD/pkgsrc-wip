# $NetBSD: Makefile,v 1.3 2014/08/11 23:10:13 thomasklausner Exp $

DISTNAME=	libvalhalla-1.0.1
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://libvalhalla.geexbox.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrbleboss@gmail.com
HOMEPAGE=	http://libvalhalla.geexbox.org/
COMMENT=	Tiny media scanner library
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--prefix=${PREFIX}

HAS_CONFIGURE=	yes

.include "../../wip/libnfo/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
