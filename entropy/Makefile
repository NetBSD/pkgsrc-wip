# $NetBSD: Makefile,v 1.18 2003/10/11 21:16:56 tvierling Exp $
#

DISTNAME=		entropy-${ENTROPY_VERSION}
PKGNAME=		entropy-${ENTROPY_VERSION:S/-/./}
WRKSRC=			${WRKDIR}/entropy-${ENTROPY_VERSION:C/-.*$//}
CATEGORIES=		security net
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Anonymous peer-to-peer networking node (similar to Freenet)

ONLY_FOR_PLATFORM=	*-*-i386 *-*-powerpc

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

ENTROPY_VERSION=	0.5.7-342

MAKE_FLAGS+=		QUIET=0
MAKE_FLAGS+=		LIBEXPAT=-lexpat LIBZ=-lz
MAKE_FLAGS+=		CC=${CC:Q} LD=${CC:Q} DEP=${CC:Q}

.if ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=		ARCH=X86
.elif ${MACHINE_ARCH} == "powerpc"
MAKE_FLAGS+=		ARCH=PPC
.endif

post-patch:
	${SED} -e '/^# /!s/^#//' <${WRKSRC}/seed.txt-dist >${WRKSRC}/seed.txt
	${RM} -f -r ${WRKSRC}/node/my0812.bdf.gz*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/entropy ${PREFIX}/bin/entropy
	${INSTALL_PROGRAM} ${WRKSRC}/storechg ${PREFIX}/bin/entropy-storechg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy/node
	${INSTALL_DATA} ${WRKSRC}/entropy.conf-dist ${PREFIX}/share/examples/entropy/entropy.conf
	${INSTALL_DATA} ${WRKSRC}/seed.txt ${PREFIX}/share/examples/entropy/
	${INSTALL_DATA} ${WRKSRC}/node/[0-9a-z]* ${PREFIX}/share/examples/entropy/node/

.include "../../mk/bsd.prefs.mk"

# "monolithic" is somehow broken at the moment
ENTROPY_STORE_TYPE?=	tree

.if ${ENTROPY_STORE_TYPE} == "tree"
MAKE_FLAGS+=		STORE_TYPE=1
.elif ${ENTROPY_STORE_TYPE} == "mysql"
MAKE_FLAGS+=		STORE_TYPE=2
MAKE_FLAGS+=		INCMYSQL=${PREFIX}/include/mysql LIBMYSQL=-lmysqlclient
LDFLAGS+=		${BUILDLINK_LDFLAGS.mysql-client}
.include "../../databases/mysql-client/buildlink2.mk"
.elif ${ENTROPY_STORE_TYPE} != "monolithic"
.error unknown ENTROPY_STORE_TYPE: ${ENTROPY_STORE_TYPE}
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
