# $NetBSD: Makefile,v 1.5 2010/12/31 18:39:56 khorben Exp $
#

DISTNAME=	libDesktop-0.0.3
PKGNAME=	deforaos-libdesktop-0.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3452/

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
