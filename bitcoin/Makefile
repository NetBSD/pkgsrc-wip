# $NetBSD$

DISTNAME=       bitcoin-0.11.2
PKGREVISION=    2
CATEGORIES=	finance
MASTER_SITES=   ${MASTER_SITE_GITHUB:=bitcoin/}
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://bitcoin.sourceforge.net/
COMMENT=	P2P electronic cash system
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake
USE_LANGUAGES=	c c++
AUTO_MKDIRS=	yes
GNU_CONFIGURE=  yes

# TODO: explain why this is necessary
CXXFLAGS+=	-std=c++0x -I${BUILDLINK_PREFIX.boost-libs}/include/boost
CXXFLAGS+=	-Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin -L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CFLAGS+=        -fPIC -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin -L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin

# TODO: explain why this is necessary, and whether it duplicates the above
CPPFLAGS+=-I${BUILDLINK_PREFIX.boost-headers}/include/boost, -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CPPFLAGS+=-L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CONFIGURE_ARGS+=  --with-boost=${BUILDLINK_PREFIX.boost-libs}

CONFIGURE_ARGS+=  --enable-hardening

# TODO: explain why adding a prefix without a -- command makes sense
CONFIGURE_ARGS+=  ${PREFIX}/include/db4
# TODO: explain why this is necessary
BUILDLINK_TRANSFORM+=   l:db_cxx:db4_cxx

RCD_SCRIPTS=	bitcoind
BUILD_DEFS+=	VARBASE
OWN_DIRS=	${VARBASE}/bitcoin
EGDIR=		${PREFIX}/share/examples/bitcoin
CONF_FILES=	${EGDIR}/bitcoin.conf ${PKG_SYSCONFDIR}/bitcoin.conf
CONF_FILES_PERMS=	${EGDIR}/bitcoin.conf ${PKG_SYSCONFDIR}/bitcoin.conf ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600

# This is currently unnecessary, but it seems likely we will find a
# file that references /usr when ${PREFIX} is appropriate.
SUBST_CLASSES+= 	pkg
SUBST_STAGE.pkg= 	post-patch
SUBST_SED.pkg=		-e "s|/usr/|${PREFIX}/|g"
SUBST_MESSAGE.pkg=	"Fixing /usr references to ${PREFIX}."

# bitcoin does not actually have releases; only snapshots of the
# repository from which a release would have been made.  Remedially
# create configure.in and similar.
pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# TODO: explain why this is necessary
# TODO: explain why bitcoint-qt is commented out
do-install:
#       ${INSTALL_PROGRAM} ${WRKSRC}/bitcoin-qt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/bitcoin-cli ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/bitcoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_LIB} -m 644 ${WRKSRC}/src/secp256k1/libsecp256k1.la ${DESTDIR}${PREFIX}/lib/bitcoin
	${INSTALL_LIB} ${WRKSRC}/src/secp256k1/.libs/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/bitcoin
	${LN} -fs ${DESTDIR}${PREFIX}/lib/bitcoin/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/bitcoin/libsecp256k1.so
	${INSTALL_DATA} -m 600 ${FILESDIR}/bitcoin.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/share/pixmaps/bitcoin128.png ${DESTDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/debian/bitcoin-qt.desktop ${DESTDIR}${PREFIX}/share/applications/

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt4-tools=	full
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
