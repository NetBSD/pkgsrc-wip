# $NetBSD: Makefile,v 1.1 2011/02/24 22:57:52 khorben Exp $

DISTNAME=	Locker-0.0.1
PKGNAME=	deforaos-locker-0.0.1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3469/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop screensaver

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
