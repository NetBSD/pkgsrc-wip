# $NetBSD: Makefile,v 1.2 2013/01/02 13:16:51 jonperkin Exp $
#

.include "../../wip/zookeeper-server/Makefile.common"

PKGNAME=	${DISTNAME:S/keeper/keeper-client/}
COMMENT=	Highly reliable distributed coordination server (client)

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ c99
USE_LIBTOOL=	yes

BUILD_DEPENDS+=	cppunit-[0-9]*:../../devel/cppunit

CONFIGURE_DIRS=	src/c

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LIBS.SunOS+=	-lnsl -lsocket

TEST_TARGET=	run-check

.include "../../mk/bsd.pkg.mk"
