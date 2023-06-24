# $NetBSD$

DISTNAME=	heimdal-7.99.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=heimdal/}
#GIT_BRANCH=	master
GIT_REVISION=	8c3c97bdf6c06200418f1a85aa22beaa441c6b23
GIT_REPO=	https://github.com/heimdal/heimdal

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://heimdal.software/
COMMENT=	Kerberos 5 implementation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON

CONFLICTS+=	arla-[0-9]*
CONFLICTS+=	mit-krb5-[0-9]*
CONFLICTS+=	openafs-[0-9]*
CONFLICTS+=	gss-[0-9]*
CONFLICTS+=	kth-krb4-[0-9]*

USE_LIBTOOL=		yes
.if !empty(GIT_REPO)
TOOL_DEPENDS+=		autoconf-archive>=0:../../devel/autoconf-archive
USE_TOOLS+=		autoconf automake autoreconf
.endif
USE_TOOLS+=		bison gmake flex:run makeinfo perl
PKGCONFIG_OVERRIDE+=	tools/heimdal-gssapi.pc.in
MAKE_ENV+=		INSTALL_CATPAGES=no

# 4.8 is not good enough, 7.0.1 is good enough, somewhere in the middle
# might suffice but I don't care to do that search at the moment.
TEXINFO_REQD+=		7.0.1

BUILD_DEFS+=		VARBASE

.include "options.mk"

HEIMDAL_HDB_DIR=	${VARBASE}/heimdal

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has multiple configure scripts
CONFIGURE_ARGS+=	--enable-kcm
CONFIGURE_ARGS+=	--enable-pthread-support
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/krb5
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-hdbdir=${HEIMDAL_HDB_DIR}
CONFIGURE_ARGS+=	--with-readline=${BUILDLINK_PREFIX.editlinereadline}
CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	${ABI:D--with-mips-abi=${ABI}}
CONFIGURE_ENV+=		COMPILE_ET=no	# build Heimdal's compile_et(1)
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
CONFIGURE_ENV+=		CLANG_FORMAT=true

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../mk/bdb.buildlink3.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
CONFIGURE_ARGS+=	CC_FOR_BUILD=${NATIVE_CC:Q}

TOOL_DEPENDS+=		${PKGNAME}:../../${PKGPATH}
CONFIGURE_ARGS+=	--with-cross-tools=${TOOLBASE:Q}/bin/

CONFIGURE_ARGS+=	ASN1_COMPILE=${TOOLBASE:Q}/bin/asn1_compile
CONFIGURE_ARGS+=	COMPILE_ET=${TOOLBASE:Q}/bin/heim_compile_et
CONFIGURE_ARGS+=	SLC=${TOOLBASE:Q}/libexec/heimdal/slc

MAKE_FLAGS+=		ASN1_COMPILE=${TOOLBASE:Q}/bin/asn1_compile
MAKE_FLAGS+=		COMPILE_ET=${TOOLBASE:Q}/bin/heim_compile_et
MAKE_FLAGS+=		SLC=${TOOLBASE:Q}/libexec/heimdal/slc
.endif

# XXX Don't detect db1 when a newer version is available; otherwise build fails
.if ${BDB_TYPE} != "db1"
CONFIGURE_ENV+=		ac_cv_funclib_dbopen=no
.endif

CFLAGS.Darwin+=		-DBIND_8_COMPAT

# Newer illumos has extended functions in glob(3C) but it's easier to
# say it doesn't for simpler PLIST.glob handling.
CONFIGURE_ENV.SunOS+=	ac_cv_func_glob_working=no

# Though Solaris has a <vis.h> header, it does something very unrelated
# to the BSD <vis.h> header.
CONFIGURE_ENV.SunOS+=	ac_cv_header_vis_h=no

PLIST_VARS+=		doxygen glob vis afskauth

.if empty(GIT_REPO)
PLIST.doxygen=		yes
.endif

.if ${OPSYS} == "SunOS"
PLIST.vis=	yes
PLIST.glob=	yes
.endif

.if ${OPSYS} == "IRIX"
PLIST.afskauth=		yes
.endif

OWN_DIRS_PERMS=		${HEIMDAL_HDB_DIR} ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
SPECIAL_PERMS+=		${PREFIX}/bin/otp ${SETUID_ROOT_PERMS}
SPECIAL_PERMS+=		${PREFIX}/bin/${KRB5_PREFIX}su ${SETUID_ROOT_PERMS}
RCD_SCRIPTS=		kadmind kcm kdc kpasswdd
INFO_FILES=		yes

TEST_TARGET=		check

# remove manpages conficting with OpenSSL keeping only the important ones
pre-configure:
.if !empty(GIT_REPO)
	@${STEP_MSG} Running autoreconf
	${RUN} cd ${WRKSRC} && autoreconf -fi
.else
	@${STEP_MSG} Removing man pages that conflict with OpenSSL
	${RUN} cd ${WRKSRC}/doc/doxyout/hcrypto && \
	${GREP} -e /hcrypto_ -e /page_ manpages > manpages.new && \
	mv manpages.new manpages
.endif

.if 0 && !empty(GIT_REPO)
pre-build:
	@${STEP_MSG} Running doxygen
	${RUN} cd ${WRKSRC}/doc && ${BUILD_MAKE_CMD} doxygen
.endif

# Linux does not have include/vis.h and expected include/glob.h.
.if ${OPSYS} == "Linux"
PLIST.vis=		yes
PLIST.glob=		yes
# Without this I get undefined references to pthread_getspecific
PTHREAD_AUTO_VARS=	yes
.endif

.if ${OPSYS} == "MirBSD"
PLIST.vis=		yes
# all of the tools need to link against pthread, force it.
PTHREAD_AUTO_VARS=	yes
.endif

.if ${OPSYS} == "Minix"
# all of the tools need to link against pthread, force it.
PTHREAD_AUTO_VARS=	yes
.endif

.include "../../lang/python/pyversion.mk"
.include "../../security/openssl/buildlink3.mk"
# integrated editline configure script that always runs checks for this
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
