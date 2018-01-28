# $NetBSD: Makefile,v 1.1 2015/03/01 15:44:34 jonthn Exp $

PKGNAME=	libvterm-0.0.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/neovim/livterm/archive/

HOMEPAGE=	http://www.leonerd.org.uk/code/libvterm/
COMMENT=	Abstract VT220/Xterm/ECMA-48 emulation library
LICENSE=	mit

GIT_REPOSITORIES=	libvterm
GIT_REPO.libvterm=	git://github.com/neovim/libvterm.git
GIT_MODULE.libvterm=	libvterm
WRKSRC=			${WRKDIR}/${GIT_MODULE.libvterm}

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config gmake perl
USE_LIBTOOL=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	vterm.pc.in

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
