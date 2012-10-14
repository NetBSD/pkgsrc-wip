# $NetBSD: Makefile,v 1.11 2012/10/14 19:56:32 khorben Exp $

DISTNAME=	libDesktop-0.0.8
PKGNAME=	deforaos-libdesktop-0.0.8
CATEGORIES=	wip
MASTER_SITES=	http://www.defora.org/os/download/download/3699/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop library

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
