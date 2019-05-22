# $NetBSD$

DISTNAME=	mona-1.4-17
CATEGORIES=	math
MASTER_SITES=	https://www.brics.dk/mona/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.brics.dk/mona/
COMMENT=	Tool that translates formulas to finite-state automata
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/mona-1.4

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison
MAKE_FILE=	makefile
USE_LANGUAGES=	c c++

.include "../../mk/bsd.pkg.mk"
