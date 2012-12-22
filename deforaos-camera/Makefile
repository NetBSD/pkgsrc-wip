# $NetBSD: Makefile,v 1.1 2012/12/22 04:01:24 khorben Exp $
#

DISTNAME=	Camera-0.0.0
PKGNAME=	deforaos-camera-0.0.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.defora.org/os/download/download/3999/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop camera
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
