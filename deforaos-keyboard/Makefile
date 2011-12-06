# $NetBSD: Makefile,v 1.2 2011/12/06 12:47:38 khorben Exp $

DISTNAME=	Keyboard-0.1.2
PKGNAME=	deforaos-keyboard-0.1.2
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3598/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop virtual keyboard

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CPPFLAGS="-D PREFIX=\\\"${PREFIX}\\\""

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
