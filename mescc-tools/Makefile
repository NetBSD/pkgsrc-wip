# $NetBSD$

DISTNAME=	mescc-tools-Release_0.6.1
PKGNAME=	${DISTNAME:S/Release_//}
CATEGORIES=	devel
MASTER_SITES=	http://git.savannah.nongnu.org/cgit/mescc-tools.git/snapshot/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/oriansj/mescc-tools/
COMMENT=	Tools for the full source bootstrapping process
LICENSE=	gnu-gpl-v3
USE_TOOLS=	gmake

NO_CONFIGURE=	YES

WRKSRC=	${WRKDIR}/mescc-tools-Release_0.6.1

MAKE_FILE=		makefile
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}

TEST_TARGET=	test

.include "../../mk/bsd.pkg.mk"
