# $NetBSD$

DISTNAME=	nauty2_8_9
PKGNAME=	nauty-2.8.9
CATEGORIES=	math
MASTER_SITES=	http://users.cecs.anu.edu.au/~bdm/nauty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cs.anu.edu.au/~bdm/nauty/
COMMENT=	Brendan McKay's graph isomorphism tester
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf
MAKE_FILE=	makefile
USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
