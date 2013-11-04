# $NetBSD: Makefile,v 1.2 2013/11/04 00:45:48 ishit Exp $

.include "Makefile.common"
COMMENT=        Yet Another Multipurpose CHunk Annotator

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=	c c++

#TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	marisa.pc.in

.include "../../mk/bsd.pkg.mk"
