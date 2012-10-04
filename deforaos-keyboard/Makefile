# $NetBSD: Makefile,v 1.4 2012/10/04 23:35:38 khorben Exp $

DISTNAME=	Keyboard-0.2.1
PKGNAME=	deforaos-keyboard-0.2.1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3696/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop virtual keyboard

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
