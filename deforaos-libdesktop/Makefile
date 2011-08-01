# $NetBSD: Makefile,v 1.7 2011/08/01 12:36:20 khorben Exp $
#

DISTNAME=	libDesktop-0.0.5
PKGNAME=	deforaos-libdesktop-0.0.5
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3561/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop library

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
