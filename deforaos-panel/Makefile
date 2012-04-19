# $NetBSD: Makefile,v 1.22 2012/04/19 14:27:29 khorben Exp $

DISTNAME=	Panel-0.2.13
PKGNAME=	deforaos-panel-0.2.13
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3668/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop panel

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../wip/deforaos-browser/buildlink3.mk"
.include "../../wip/deforaos-keyboard/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
