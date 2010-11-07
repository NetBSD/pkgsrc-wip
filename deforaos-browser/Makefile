# $NetBSD: Makefile,v 1.9 2010/11/07 15:15:46 khorben Exp $

DISTNAME=	Browser-0.3.2
PKGNAME=	deforaos-browser-0.3.2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.defora.org/os/download/download/3432/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop file browser

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
