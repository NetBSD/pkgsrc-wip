# $NetBSD: Makefile,v 1.100 2019/05/06 08:20:32 wiz Exp $

DISTNAME=	krb5-1.16.2
ABI?=		32
PKGNAME=	compat${ABI}_mit-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://web.mit.edu/kerberos/dist/krb5/${PKGVERSION_NOREV:R}/

MAINTAINER=	tez@NetBSD.org
HOMEPAGE=	https://web.mit.edu/kerberos/
COMMENT=	MIT Kerberos 5 authentication system

MAKE_JOBS_SAFE=		no

WRKSRC=		${WRKDIR}/${DISTNAME}/src

BUILD_TARGET=	generate-files-mac all

BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/emul/netbsd32

.include "../../mk/bsd.prefs.mk"

CONFLICTS+=	heimdal-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PREFIX32=		emul/netbsd32
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${PREFIX32}
USE_TOOLS+=		autoconf gzip m4 msgfmt perl
.if ${OPSYS} == "SunOS"
USE_TOOLS+=		bison
.else
USE_TOOLS+=		yacc
.endif

# The actual KDC databases are stored in ${MIT_KRB5_STATEDIR}/krb5kdc.
MIT_KRB5_STATEDIR?=	${VARBASE}
FILES_SUBST+=		MIT_KRB5_STATEDIR=${MIT_KRB5_STATEDIR}

BUILD_DEFS+=		VARBASE

CONFIGURE_ARGS+=	--localstatedir=${MIT_KRB5_STATEDIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-dns-for-realm
CONFIGURE_ARGS+=	--disable-kdc-lookaside-cache
CONFIGURE_ARGS+=	--disable-thread-support
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ARGS+=	--enable-pkgsrc-libtool
CONFIGURE_ARGS+=	--without-system-verto
CONFIGURE_ARGS+=	--disable-aesni
CONFIGURE_ENV+=		BUILDLINK_PREFIX_OPENSSL=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ENV+=		DEFKTNAME=FILE:${PKG_SYSCONFDIR}/krb5.keytab
MAKE_ENV+=		ROOT_USER=${ROOT_USER}
LIBS.SunOS=		-lrt

PATCH_DIST_ARGS=	-d ${WRKSRC} -p2

INFO_FILES=		YES

OWN_DIRS_PERMS=		${MIT_KRB5_STATEDIR}/krb5kdc			\
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
#RCD_SCRIPTS=		kadmind kdc

INSTALLATION_DIRS=	${PREFIX32}/bin ${PREFIX32}/include/gssapi ${PREFIX32}/include/gssrpc   \				 ${PREFIX32}/info ${PREFIX32}/man/man1 ${PREFIX32}/man/man5 \
			${PREFIX32}/man/man7 ${PREFIX32}/man/man8 ${PREFIX32}/sbin \
			${PREFIX32}/share/examples/krb5			\
			${PREFIX32}/share/et				\
			${PREFIX32}/share/examples/rc.d			\
			${PREFIX32}/share/gnats				\
			${PREFIX32}/lib/krb5/plugins/kdb		\
			${PREFIX32}/lib/krb5/plugins/preauth		\
			${PREFIX32}/lib/krb5/plugins/tls		\
			${PREFIX32}/include/krb5 ${PREFIX32}/include/kadm5 \
			${PREFIX32}/lib/pkgconfig

pre-configure:
	cd ${WRKSRC} && autoconf -I ${WRKSRC} -f

post-install:
	cd ${WRKDIR}/${DISTNAME}/doc;					\
	for f in *.info *.info-[0-9]*; do				\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_MAN} "$$f" ${DESTDIR}${PREFIX}/${PREFIX32}/info; \
	done

BUILDLINK_API_DEPENDS.openssl+= openssl>=1.0.1
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
