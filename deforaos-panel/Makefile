# $NetBSD: Makefile,v 1.6 2010/04/11 23:14:40 khorben Exp $

DISTNAME=	Panel-0.0.5
PKGNAME=	deforaos-panel-0.0.5
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3326/

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
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
