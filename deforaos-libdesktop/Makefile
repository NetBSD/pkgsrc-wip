# $NetBSD: Makefile,v 1.15 2013/11/06 01:18:39 khorben Exp $
#

DISTNAME=	libDesktop-0.0.10
PKGNAME=	deforaos-libdesktop-0.0.10
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4293/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop library

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
