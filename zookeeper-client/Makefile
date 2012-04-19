# $NetBSD: Makefile,v 1.1.1.1 2012/04/19 10:32:38 fhajny Exp $
#

.include "../../wip/zookeeper-server/Makefile.common"

PKGNAME=	${DISTNAME:S/keeper/keeper-client/}
COMMENT=	Highly reliable distributed coordination server (client)

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++ c99
USE_LIBTOOL=	yes

BUILD_DEPENDS+=	cppunit-[0-9]*:../../devel/cppunit

WRKSRC=		${WRKDIR}/${DISTNAME}/src/c
PATCH_ARGS=	-d ${WRKDIR}/${DISTNAME} --forward --quiet -E ${PATCH_STRIP:Q}

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LIBS.SunOS+=	-lnsl -lsocket

TEST_TARGET=	run-check

.include "../../mk/bsd.pkg.mk"
