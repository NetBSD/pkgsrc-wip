# $NetBSD: Makefile,v 1.1 2009/12/30 22:25:54 khorben Exp $
#

DISTNAME=	libDesktop-0.0.1
PKGNAME=	deforaos-libdesktop-0.0.1
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3314/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop library

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
