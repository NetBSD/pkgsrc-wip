# $NetBSD: Makefile,v 1.1 2015/02/21 16:22:19 jonthn Exp $

DISTNAME=	libtermkey-0.18
CATEGORIES=	devel
MASTER_SITES=	http://www.leonerd.org.uk/code/libtermkey/

HOMEPAGE=	http://www.leonerd.org.uk/code/libtermkey/
COMMENT=	library to process keyboard entry from terminal-based programs
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config gmake
USE_LIBTOOL=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

PKGCONFIG_OVERRIDE+=	termkey.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
