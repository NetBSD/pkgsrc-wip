# $NetBSD: Makefile,v 1.8 2004/11/06 03:35:18 tvierling Exp $
#

DISTNAME=	GNUnet-0.6.4a
PKGNAME=	${DISTNAME:S/GNU/gnu/}
CATEGORIES=	x11
MASTER_SITES=	http://www.ovmj.org/GNUnet/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.ovmj.org/GNUnet/
COMMENT=	Framework for secure p2p networking

BUILD_USES_MSGFMT=	yes

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
PLIST_SRC=		${WRKDIR}/PLIST.src
USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

PTHREAD_OPTS=		require native
LDFLAGS+=		-lpthread -lintl

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnunet
PKG_SUPPORTED_OPTIONS=	bdb gdbm libgcrypt openssl tdb

# some sane defaults to use base OS functionality where appropriate
.if !empty(OPSYS:M*BSD)
PKG_DEFAULT_OPTIONS+=	openssl
.else
PKG_DEFAULT_OPTIONS+=	libgcrypt
.endif

.include "../../mk/bsd.options.mk"

CONFIGURE_ARGS+=	--with-extractor=${BUILDLINK_PREFIX.libextractor}
CONFIGURE_ARGS+=        --without-gtk
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

BUILD_DEFS+=		USE_INET6
.if defined(USE_INET6)
CONFIGURE_ARGS+=	--with-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db4 db3 db2
.include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-bdb=${BDBBASE}
GNUNET_PLIST_ADD+=	lib/libgnunetafs_database_bdb.la
.else
CONFIGURE_ARGS+=	--without-bdb
.endif

.if !empty(PKG_OPTIONS:Mgdbm)
.include "../../databases/gdbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
GNUNET_PLIST_ADD+=	lib/libgnunetafs_database_gdbm.la
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if !empty(PKG_OPTIONS:Mtdb)
.include "../../databases/tdb/buildlink3.mk"
CONFIGURE_ARGS+=	--with-tdb=${BDBBASE}
GNUNET_PLIST_ADD+=	lib/libgnunetafs_database_tdb.la
.else
CONFIGURE_ARGS+=	--without-tdb
.endif

# libgcrypt is used in preference to openssl, per gnunet configure.ac
.if !empty(PKG_OPTIONS:Mlibgcrypt)
.include "../../security/libgcrypt/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libgcrypt-prefix=${BUILDLINK_PREFIX.libgcrypt}
CONFIGURE_ARGS+=	--without-crypto
.elif !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-crypto=${BUILDLINK_PREFIX.libgcrypt}
CONFIGURE_ENV+=		LIBGCRYPT_CONFIG=/nonexistent
.else
.error must use one of "libgcrypt" or "openssl" in PKG_OPTIONS.gnunet
.endif

post-patch:
	cd ${WRKSRC} && for f in contrib/gnunet.* src/include/gnunet_util.h doc/man/*.?; do \
		${ECHO} $$f && \
		${SED} -e 's,/etc/gnunet\.conf,${PKG_SYSCONFDIR}/gnunet.conf,g' $$f >$$f.tmp && \
		${MV} -f $$f.tmp $$f; \
	done
	${RM} -f ${WRKSRC}/src/util/generate_*_conf.c

post-build:
	${CP} -f ${PKGDIR}/PLIST ${PLIST_SRC}
.for f in ${GNUNET_PLIST_ADD}
	${ECHO} '$f' >>${PLIST_SRC}
.endfor

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
