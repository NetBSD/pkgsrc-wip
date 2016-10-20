# $NetBSD$

#DISTNAME=	v1.8.3
DISTNAME=       v1.10.0
PKGREVISION=    RC-1
PKGNAME=	dogecoin-${DISTNAME:S/v//1}
CATEGORIES=	finance
MASTER_SITES=	https://github.com/dogecoin/dogecoin/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dogecoin.com/
COMMENT=	Open source peer-to-peer digital currency, favored by Shiba Inus
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	aclocal autoconf autoheader automake gmake libtoolize pkg-config
USE_LANGUAGES=	c c++
AUTO_MKDIRS=    yes
HAS_CONFIGURE=  yes

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
#CXXFLAGS+=	-std=c++0x
CXXFLAGS+=      -DBOOST_VARIANT_USE_RELAXED_GET_BY_DEFAULT=1
CXXFLAGS+=      -std=c++0x -I${BUILDLINK_PREFIX.boost-libs}/include/boost
CXXFLAGS+=      -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/dogecoin -L${BUILDLINK_PREFIX.boost-libs}/lib/dogecoin
CFLAGS+=        -fPIC -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/dogecoin -L${BUILDLINK_PREFIX.boost-libs}/lib/dogecoin
BOOST_LDFLAGS=  -L${BUILDLINK_PREFIX.boost-libs}/lib
BOOST_CPPFLAGS= -I${BUILDLINK_PREFIX.boost-libs}/include
CPPFLAGS+=-I${BUILDLINK_PREFIX.boost-headers}/include/boost, -Wl,-R${BUILDLINK_PREFIX.boost-libs}/lib/dogecoin
CPPFLAGS+=-L${BUILDLINK_PREFIX.boost-libs}/lib/dogecoin

LIBTOOLIZE=	${PREFIX}/bin/libtoolize

SUBST_CLASSES+=			autotools
SUBST_FILES.autotools=		autogen.sh
SUBST_MESSAGE.autotools=	Fixing path to autoreconf.
SUBST_SED.autotools=		-e "s|autoreconf|${PREFIX}/bin/autoreconf|1"
SUBST_STAGE.autotools=		post-patch

CONFIGURE_ARGS+=		--enable-hardening --enable-debug
CONFIGURE_ARGS+=		--with-boost=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=		--with-incompatible-bdb
BUILDLINK_TRANSFORM+=		l:db_cxx:db5_cxx
CONFIGURE_ARGS+=  		${PREFIX}/include/db5
INSTALLATION_DIRS+=		bin sbin share/examples/dogecoin

#CHECK_PORTABILITY_SKIP=configure

RCD_SCRIPTS=	dogecoind
OWN_DIRS=	${VARBASE}/dogecoin
EGDIR=		${PREFIX}/share/examples/dogecoin
CONF_FILES=	${EGDIR}/dogecoin.conf ${PKG_SYSCONFDIR}/dogecoin.conf
CONF_FILES_PERMS=	${EGDIR}/dogecoin.conf ${PKG_SYSCONFDIR}/dogecoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600

.include "options.mk"

pre-configure:
	cd ${WRKSRC};             \
        ${LIBTOOLIZE} --force;    \
        ${PREFIX}/bin/aclocal;    \
        ${PREFIX}/bin/autoheader; \
        ${PREFIX}/bin/automake --add-missing; \
        ${PREFIX}/bin/autoconf

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/dogecoind \
		${DESTDIR}${PREFIX}/sbin/dogecoind
	${INSTALL_DATA} -m 600 ${FILESDIR}/dogecoin.conf ${DESTDIR}${EGDIR}

.include "../../databases/db5/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

