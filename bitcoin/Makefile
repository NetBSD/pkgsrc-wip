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

# TODO: Explain why this is necessary.
CFLAGS+=        -fPIC
# TODO: Explain why this is necessary.
CXXFLAGS+=	-std=c++0x

# TODO: Explain why these are necessary.
CPPFLAGS+=	-I${BUILDLINK_PREFIX.boost-headers}/include/boost, -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CPPFLAGS+=	-L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CFLAGS+=	-Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin -L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin
CXXFLAGS+=	-Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin -L${BUILDLINK_PREFIX.boost-libs}/lib/bitcoin

# configure does not look in PREFIX for boost unless instructed.
CONFIGURE_ARGS+=  --with-boost=${BUILDLINK_PREFIX.boost-libs}
# TODO: Explain why this is necessary; the -I of the include dir
# should be present, and bitcoin's configure should know about what
# appears to be a standard include sub-directory.
CXXFLAGS+=	-I${BUILDLINK_PREFIX.boost-libs}/include/boost

CONFIGURE_ARGS+=  --enable-hardening

# pkgsrc's db4 package installs as db4_, but bitcoin looks for db_.
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
SUBST_MESSAGE.pkg=	Fixing /usr references to ${PREFIX}.

# bitcoin does not actually have releases; only snapshots of the
# repository from which a release would have been made.  Remedially
# create configure.in and similar.
pre-configure:
	cd ${WRKSRC} && ./autogen.sh

# bitcoin appears to have a functioning install target, so this should
# not be necessary.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bitcoin-cli ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/.libs/bitcoind ${DESTDIR}${PREFIX}/sbin
	${INSTALL_LIB} -m 644 ${WRKSRC}/src/secp256k1/libsecp256k1.la ${DESTDIR}${PREFIX}/lib/bitcoin
	${INSTALL_LIB} ${WRKSRC}/src/secp256k1/.libs/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/bitcoin
	${LN} -fs ${DESTDIR}${PREFIX}/lib/bitcoin/libsecp256k1.so.0 ${DESTDIR}${PREFIX}/lib/bitcoin/libsecp256k1.so
	${INSTALL_DATA} -m 600 ${FILESDIR}/bitcoin.conf ${DESTDIR}${EGDIR}

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
