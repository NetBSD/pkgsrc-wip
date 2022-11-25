# $NetBSD$

DISTNAME=	mona-1.4-18
CATEGORIES=	math
MASTER_SITES=	http://www.brics.dk/mona/download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.brics.dk/mona/index.html
COMMENT=	Tool that translates formulas to finite-state automata
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/mona-1.4

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
MAKE_FILE=	makefile
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex

.include "../../mk/bsd.pkg.mk"
