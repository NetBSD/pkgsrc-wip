# $NetBSD: Makefile,v 1.3 2011/12/14 23:32:02 khorben Exp $

DISTNAME=	Locker-0.1.1
PKGNAME=	deforaos-locker-0.1.1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3604/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop screensaver

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../wip/deforaos-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
