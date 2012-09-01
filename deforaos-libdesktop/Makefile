# $NetBSD: Makefile,v 1.9 2012/09/01 16:11:42 khorben Exp $
#

DISTNAME=	libDesktop-0.0.7
PKGNAME=	deforaos-libdesktop-0.0.7
CATEGORIES=	devel
MASTER_SITES=	http://www.defora.org/os/download/download/3682/

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
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
