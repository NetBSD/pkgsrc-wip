# $NetBSD: Makefile,v 1.31 2003/11/11 22:02:41 tvierling Exp $
#

DISTNAME=		entropy-${ENTROPY_VERSION}
PKGNAME=		entropy-${ENTROPY_VERSION:S/-/./}
WRKSRC=			${WRKDIR}/entropy-${ENTROPY_VERSION:C/-.*$//}
CATEGORIES=		security net
MASTER_SITES=		http://entropy.stop1984.com/files/ \
			http://www.duh.org/entropy/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://entropy.stop1984.com/
COMMENT=		Anonymous peer-to-peer networking node (similar to Freenet)

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes

ENTROPY_VERSION=	0.6.1-362

CONFIGURE_ARGS+=	--enable-verbose

post-patch:
	${SED} -e '/^# /!s/^#//' <${WRKSRC}/seed.txt-dist >${WRKSRC}/seed.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/entropy ${PREFIX}/bin/entropy
	${INSTALL_PROGRAM} ${WRKSRC}/storechg ${PREFIX}/bin/entropy-storechg
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/entropy/node
	${INSTALL_DATA} ${WRKSRC}/entropy.conf-dist ${PREFIX}/share/examples/entropy/entropy.conf
	${INSTALL_DATA} ${WRKSRC}/seed.txt ${PREFIX}/share/examples/entropy/
	${INSTALL_DATA} ${WRKSRC}/node/[0-9a-z]* ${PREFIX}/share/examples/entropy/node/

.include "../../mk/bsd.prefs.mk"

# tree is most efficient on *ix; can also be "monolithic" or "mysql"
ENTROPY_STORE_TYPE?=	tree

.if ${ENTROPY_STORE_TYPE} == "tree"
CONFIGURE_ARGS+=	--with-tree --with-svid-sem
.elif ${ENTROPY_STORE_TYPE} == "mysql"
CONFIGURE_ARGS+=	--with-mysql=${LOCALBASE} --with-svid-sem
.include "../../databases/mysql-client/buildlink2.mk"
.elif ${ENTROPY_STORE_TYPE} == "monolithic"
ONLY_FOR_PLATFORM=	*-*-i386 *-*-powerpc
.else
.error unknown ENTROPY_STORE_TYPE: ${ENTROPY_STORE_TYPE}
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
