# $NetBSD: Makefile,v 1.5 2010/11/07 15:41:50 khorben Exp $

DISTNAME=	Surfer-0.2.1
PKGNAME=	deforaos-surfer-0.2.1
CATEGORIES=	www
MASTER_SITES=	http://www.defora.org/os/download/download/3433/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop web browser

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
