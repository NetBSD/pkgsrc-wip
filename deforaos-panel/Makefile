# $NetBSD: Makefile,v 1.12 2011/03/17 11:26:50 khorben Exp $

DISTNAME=	Panel-0.2.4
PKGNAME=	deforaos-panel-0.2.4
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3510/

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
