# $NetBSD: Makefile,v 1.1 2009/12/30 22:25:54 khorben Exp $

DISTNAME=	Mixer-0.0.1
PKGNAME=	deforaos-mixer-0.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.defora.org/os/download/download/3317/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop audio mixer

LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
