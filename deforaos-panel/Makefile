# $NetBSD: Makefile,v 1.16 2011/07/16 03:03:28 khorben Exp $

DISTNAME=	Panel-0.2.8
PKGNAME=	deforaos-panel-0.2.8
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3552/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop panel

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
