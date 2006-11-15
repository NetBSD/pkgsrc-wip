# $NetBSD: Makefile,v 1.1.1.1 2006/11/15 00:05:50 dhowland Exp $
#

DISTNAME=	sis-1.3.6
CATEGORIES=	cad
MASTER_SITES=	http://embedded.eecs.berkeley.edu/Alumni/pchong/sis/

MAINTAINER=	dhowland@users.sourceforge.net
HOMEPAGE=	http://embedded.eecs.berkeley.edu/Alumni/pchong/sis.html
COMMENT=	Classic logic synthesis tool

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

# the makefiles don't install the data dirs properly, must pre-create
pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sis
	${INSTALL_DATA_DIR} ${PREFIX}/share/sis/espresso_examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/sis/espresso_examples/doc
	${INSTALL_DATA_DIR} ${PREFIX}/share/sis/espresso_examples/indust
	${INSTALL_DATA_DIR} ${PREFIX}/share/sis/espresso_examples/math
	${INSTALL_DATA_DIR} ${PREFIX}/share/sis/espresso_examples/random

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
