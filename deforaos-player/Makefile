# $NetBSD: Makefile,v 1.1 2009/09/20 12:34:16 khorben Exp $
#
# TODO: add an embedded option

DISTNAME=	Player-0.1.2
PKGNAME=	deforaos-player-0.1.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.defora.org/os/download/download/3277/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop media player

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../wip/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
