# $NetBSD: Makefile,v 1.1.1.1 2003/07/04 19:32:38 tvierling Exp $
#

DISTNAME=		entropy-${ENTROPY_VERSION}
PKGNAME=		entropy-${ENTROPY_VERSION:S/-/./}
WRKSRC=			${WRKDIR}/entropy-${ENTROPY_VERSION:C/-.*$//}
CATEGORIES=		wip
MASTER_SITES=		http://entropy.stop1984.com/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@pobox.com
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Anonymous peer-to-peer networking node (similar to Freenet)

ONLY_FOR_PLATFORM=	*-*-i386 *-*-powerpc

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

ENTROPY_VERSION=	0.4.2-283

MAKE_FLAGS+=		QUIET=0
MAKE_FLAGS+=		LIBEXPAT=-lexpat LIBZ=-lz
MAKE_FLAGS+=		CC=${CC:Q} LD=${CC:Q} DEP=${CC:Q}

.if ${MACHINE_ARCH} == "i386"
MAKE_FLAGS+=		ARCH=X86
.elif ${MACHINE_ARCH} == "powerpc"
MAKE_FLAGS+=		ARCH=PPC
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/entropy ${PREFIX}/bin/entropy
	${INSTALL_PROGRAM} ${WRKSRC}/storechg ${PREFIX}/bin/entropy-storechg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy/node
	${INSTALL_DATA} ${WRKSRC}/entropy.conf-dist ${PREFIX}/share/examples/entropy/entropy.conf
	${INSTALL_DATA} ${WRKSRC}/seed.txt-dist ${PREFIX}/share/examples/entropy/seed.txt
	${INSTALL_DATA} ${WRKSRC}/node/[0-9]* ${WRKSRC}/node/[a-z]* ${PREFIX}/share/examples/entropy/node/

.include "../../devel/zlib/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
