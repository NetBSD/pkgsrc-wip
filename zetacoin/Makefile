# $NetBSD$

#DISTNAME=	v0.9.2.2
DISTNAME=	v0.9.2.6
PKGNAME=	zetacoin-${DISTNAME:S/v//1}
CATEGORIES=	finance
MASTER_SITES=	https://github.com/zetacoin/zetacoin/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zetacoin.com/
COMMENT=	Secure and fast digital cryptocurrency
LICENSE=	mit

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config autoconf aclocal autoheader automake libtoolize
USE_LANGUAGES=	c++ c
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
AUTO_MKDIRS=	yes
#CXXFLAGS+=	-std=c++0x
LIBTOOLIZE=	${PREFIX}/bin/libtoolize

SUBST_CLASSES+=			autotools
SUBST_FILES.autotools=		autogen.sh
SUBST_MESSAGE.autotools=	Fixing path to autoreconf.
SUBST_SED.autotools=		-e "s|autoreconf|${PREFIX}/bin/autoreconf|1"
SUBST_STAGE.autotools=		post-patch

CONFIGURE_ARGS+=		--enable-hardening --enable-debug
CONFIGURE_ARGS+=		--with-boost=${BUILDLINK_PREFIX.boost-libs}
BUILDLINK_TRANSFORM+=		l:db_cxx:db4_cxx

CHECK_PORTABILITY_SKIP=configure

RCD_SCRIPTS=	zetacoind
OWN_DIRS=	${VARBASE}/zetacoin
EGDIR=		${PREFIX}/share/examples/zetacoin
CONF_FILES=	${EGDIR}/zetacoin.conf ${PKG_SYSCONFDIR}/zetacoin.conf
CONF_FILES_PERMS=	${EGDIR}/zetacoin.conf ${PKG_SYSCONFDIR}/zetacoin.conf ${ROOT_USER} ${ROOT_GROUP} 0600

PLIST_VARS+=	tests qt

.include "options.mk"

pre-configure:
	cd ${WRKSRC};             \
        ${LIBTOOLIZE} --force;    \
        ${PREFIX}/bin/aclocal;    \
        ${PREFIX}/bin/autoheader; \
        ${PREFIX}/bin/automake --add-missing; \
        ${PREFIX}/bin/autoconf

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/zetacoind \
		${DESTDIR}${PREFIX}/sbin/zetacoind
	${INSTALL_DATA} -m 600 ${FILESDIR}/zetacoin.conf ${DESTDIR}${EGDIR}

.include "../../databases/db4/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
