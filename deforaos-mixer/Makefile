# $NetBSD: Makefile,v 1.10 2012/09/28 21:24:34 asau Exp $

DISTNAME=	Mixer-0.1.0
PKGNAME=	deforaos-mixer-0.1.0
CATEGORIES=	audio
MASTER_SITES=	http://www.defora.org/os/download/download/3658/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop audio mixer

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "options.mk"

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
