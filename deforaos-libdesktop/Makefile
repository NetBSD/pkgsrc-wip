# $NetBSD: Makefile,v 1.2 2010/01/11 00:20:06 khorben Exp $
#

DISTNAME=	libDesktop-0.0.1
PKGNAME=	deforaos-libdesktop-0.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3314/

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
