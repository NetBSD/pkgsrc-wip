# $NetBSD: Makefile,v 1.3 2012/09/28 21:24:34 asau Exp $

DISTNAME=	Keyboard-0.1.2
PKGNAME=	deforaos-keyboard-0.1.2
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3598/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop virtual keyboard

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CPPFLAGS="-D PREFIX=\\\"${PREFIX}\\\""

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
