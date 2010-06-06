# $NetBSD: Makefile,v 1.3 2010/06/06 15:22:21 khorben Exp $
#

DISTNAME=	libDesktop-0.0.2
PKGNAME=	deforaos-libdesktop-0.0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3357/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop library

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
