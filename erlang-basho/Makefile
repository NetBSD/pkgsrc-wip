# $NetBSD$

DISTNAME=		otp_src_${DIST_VERSION_MAJOR}${DIST_VERSION_MINOR:D-basho${DIST_VERSION_MINOR}}
PKGNAME=		erlang-basho-${ERLANG_VERSION}
CATEGORIES=		lang
MASTER_SITES=		http://s3.amazonaws.com/downloads.basho.com/erlang/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://github.com/basho/otp/
COMMENT=		Erlang/OTP fork by Basho
LICENSE=		erlang-public-license

CONFLICTS+=		erlang-[0-9]*

DIST_SUBDIR=		basho
WRKSRC=			$(WRKDIR)/OTP_${DIST_VERSION_MAJOR}${DIST_VERSION_MINOR:D_basho${DIST_VERSION_MINOR}}

GNU_CONFIGURE=		yes
USE_GNU_CONFIGURE_HOST=	${USE_CROSS_COMPILE}
OVERRIDE_DIRDEPTH=	4
USE_TOOLS+=		autoconf flex gmake perl:run

.include "../../mk/bsd.prefs.mk"
.include "options.mk"
.include "Makefile.versions"

PTHREAD_OPTS+=		require native
CONFIGURE_ARGS+=	--enable-threads
CONFIGURE_ARGS+=	--disable-hipe
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--without-javac

SUBST_CLASSES+=		target
SUBST_STAGE.target=	post-patch
SUBST_FILES.target=	make/target.mk
SUBST_SED.target=	-e "s|=.*config.guess)|= ${MACHINE_GNU_PLATFORM}|"
SUBST_MESSAGE.target=	Fixing target name.

.if !empty(MACHINE_PLATFORM:MNetBSD-5.*)
.  if	empty(MACHINE_PLATFORM:M*i386)	&&\
	empty(MACHINE_PLATFORM:M*sparc)	&&\
	empty(MACHINE_PLATFORM:M*sparc64) &&\
	empty(MACHINE_PLATFORM:M*powerpc) &&\
	empty(MACHINE_PLATFORM:M*x86_64)
CONFIGURE_ARGS+=	--disable-native-ethr-impls\
			--disable-smp-require-native-atomics
.  endif
.endif
.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--disable-sctp
.endif
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
CONFIGURE_ARGS+=	--enable-kernel-poll
.endif

MAKE_ENV+=		DESTDIR=${DESTDIR}

REPLACE_INTERPRETER+=	escript
REPLACE.escript.old=	.*escript
REPLACE.escript.new=	${LOCALBASE}/bin/escript
REPLACE_FILES.escript=	\
	lib/reltool/examples/display_args \
	lib/reltool/examples/mnesia_core_dump_viewer \
	lib/snmp/src/compile/snmpc.src \
	lib/erl_docgen/priv/bin/codeline_preprocessing.escript \
	lib/erl_docgen/priv/bin/xml_from_edoc.escript \
	lib/diameter/bin/diameterc

TEST_TARGET=		tests
TEST_MAKE_FLAGS=	ERL_TOP=${WRKSRC}
REPLACE_PERL+=		make/make_emakefile

pre-configure:
	cd ${WRKSRC} && ./otp_build autoconf

post-install:
	chmod -R go-w ${DESTDIR}${PREFIX}/lib/erlang/lib

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
