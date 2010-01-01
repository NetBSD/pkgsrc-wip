# $NetBSD: Makefile,v 1.2 2010/01/01 22:42:31 thomasklausner Exp $
#
# TODO: add an embedded option

DISTNAME=	Panel-0.0.3
PKGNAME=	deforaos-panel-0.0.3
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3281/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop panel

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
