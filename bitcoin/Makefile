# $NetBSD$

# TODO: update to latest release
DISTNAME=       bitcoin-0.11.2
PKGREVISION=    3
CATEGORIES=	finance
MASTER_SITES=   ${MASTER_SITE_GITHUB:=bitcoin/}
GITHUB_TAG=     v${PKGVERSION_NOREV}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://bitcoin.sourceforge.net/
COMMENT=	P2P electronic cash system
LICENSE=	mit

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake
AUTO_MKDIRS=	yes
GNU_CONFIGURE=  yes

USE_LANGUAGES=	c c++
# It's not clear what dialect of C++ bitcoin is in, and
# if it needs explicit flags (c++0x was previously set).
# For now, leave it out.
#CXXFLAGS+=	-std=c++0x

# TODO: Explain why this is necessary.
CFLAGS+=        -fPIC

# configure does not look in PREFIX for boost unless instructed.
CONFIGURE_ARGS+=  --with-boost=${BUILDLINK_PREFIX.boost-libs}
# TODO: Explain why this is necessary; the -I of the include dir
# should be present, and bitcoin's configure should know about what
# appears to be a standard include sub-directory.
CXXFLAGS+=	-I${BUILDLINK_PREFIX.boost-libs}/include/boost

CONFIGURE_ARGS+=  --enable-hardening

# pkgsrc's db4 package installs as db4_, but bitcoin looks for db_.
BUILDLINK_TRANSFORM+=   l:db_cxx:db4_cxx

# TODO: (After updating,) file bug with bitcoin about not having
# proper RPATH to its own libary.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/bitcoin -L${PREFIX}/lib/bitcoin

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

# TODO: bitcoin appears to have a functioning install target, so this should
# not be necessary.
# TODO: bitcoind is a bin_PROGRAM, not sbin_PROGRAM, per upstream.
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
