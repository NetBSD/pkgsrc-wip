# $NetBSD: Makefile,v 1.1 2015/03/01 15:44:34 jonthn Exp $

DISTNAME=	libvterm-0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.leonerd.org.uk/code/libvterm/

HOMEPAGE=	http://www.leonerd.org.uk/code/libvterm/
COMMENT=	Abstract VT220/Xterm/ECMA-48 emulation library
LICENSE=	mit

USE_TOOLS+=	pkg-config gmake perl
USE_LIBTOOL=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	vterm.pc.in

.include "../../mk/bsd.pkg.mk"
