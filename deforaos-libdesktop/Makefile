# $NetBSD: Makefile,v 1.10 2012/09/28 21:24:34 asau Exp $
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

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
