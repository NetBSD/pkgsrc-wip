# $NetBSD: Makefile,v 1.82 2024/01/27 13:56:37 mef Exp $

# Work in Progress to update from anciend base version.
# Right now it could work on plain Linux, but gives weird
# linker error with custom toolchain (maybe also with gcc
# from pkgsrc?). PLIST might need work, as does the Python
# part. How much does it care about Python version?

DISTNAME=	gdb-16.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceware.org/gdb/
COMMENT=	Symbolic debugger for multiple language frontends
LICENSE=	gnu-gpl-v3

NOT_FOR_PLATFORM+=	Darwin-*-aarch64

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=      c++17

BROKEN_GETTEXT_DETECTION=	yes
GNU_CONFIGURE=			yes
GNU_CONFIGURE_STRICT=		no # has sub-configures
USE_PKGLOCALEDIR=		yes
USE_LIBTOOL=			yes
USE_TOOLS+=			gmake msgfmt makeinfo perl:build bash:run
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=			install-gdb install-gdbsupport
TEST_TARGET=			check
INFO_FILES=			yes
CONFIGURE_ENV+=			CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

# wants ncurses.h
FAKE_NCURSES=			yes

REPLACE_INTERPRETER+=   envbash
REPLACE.envbash.old=    '/usr/bin/env\ bash'
REPLACE.envbash.new=    ${PREFIX}/bin/bash
REPLACE_FILES.envbash=  gdb/gcore.in gdb/gstack-1.in

# In gdb/configure, depcomp is parsed with sed.
SUBST_CLASSES+=			fix-depcomp
SUBST_STAGE.fix-depcomp+=	pre-configure
SUBST_MESSAGE.fix-depcomp+=	Read depcomp directly
SUBST_FILES.fix-depcomp+=	gdb/configure gdbserver/configure
SUBST_FILES.fix-depcomp+=	gdbsupport/configure
SUBST_FILES.fix-depcomp+=	gnulib/configure libctf/configure
SUBST_SED.fix-depcomp+=		-e 's,< ./depcomp,${_OVERRIDE_PATH.depcomp},'

CONFIGURE_ARGS+=	--disable-gprofng
CONFIGURE_ARGS+=	--disable-gold
CONFIGURE_ARGS+=	--disable-gas
CONFIGURE_ARGS+=	--disable-ld

CONFIGURE_ARGS+=	--enable-targets=all

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	gcore
.if (${OPSYS} == "SunOS" || ${OPSYS} == "NetBSD" \
    || ${OPSYS} == "Linux" || ${OPSYS} == "FreeBSD")
PLIST.gcore=	yes
.endif

PLIST_VARS+=	gdbserver
.if ${OPSYS} == "Linux" || \
	(${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "x86_64")
INSTALL_TARGET+=	install-gdbserver
PLIST.gdbserver=	yes
.endif

.if ${OPSYS} == "SunOS"
# Work around a bug in gdb's configure
CONFIGURE_ENV+=		ac_cv_header_curses_h=yes
.elif ${OPSYS} == "NetBSD"
.include "../../mk/curses.buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses
CONFIGURE_ARGS+=	--with-separate-debug-dir=/usr/libdata/debug
.endif

CONFIGURE_DIRS=		${WRKDIR}/build
CONFIGURE_SCRIPT=	${WRKSRC}/configure

post-extract:
	${MKDIR} ${WRKDIR}/build
.include "../../math/mpfr/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
