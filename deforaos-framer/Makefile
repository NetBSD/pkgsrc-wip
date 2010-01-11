# $NetBSD: Makefile,v 1.2 2010/01/11 00:20:06 khorben Exp $
#
# TODO: add an embedded option

DISTNAME=	Framer-0.0.0
PKGNAME=	deforaos-framer-0.0.0
CATEGORIES=	wm
MASTER_SITES=	http://www.defora.org/os/download/download/3291/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop window manager

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
