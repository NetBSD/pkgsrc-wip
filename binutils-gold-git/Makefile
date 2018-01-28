# $NetBSD: Makefile,v 1.11 2015/03/15 14:22:19 bsiegert Exp $
#

DISTNAME=			binutils-gold-8.0
CATEGORIES=			devel
GIT_REPOSITORIES=		binutils-gold
#GIT_REPO.binutils-gold=	git://sourceware.org/git/binutils-gdb.git # broken?
#GIT_REPO.binutils-gold=	http://sourceware.org/git/binutils-gdb.git # broken?
GIT_REPO.binutils-gold=		https://github.com/wallento/binutils-gdb.git
#GIT_DEEP_CLONE.binutils-gold=	yes # server dies on shallow clones
WRKSRC=				${WRKDIR}/binutils-gold

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/binutils/
COMMENT=	Fast linker for ELF files
LICENSE=	gnu-gpl-v3

NOT_FOR_PLATFORM+=	DragonFly-*-*

USE_LANGUAGES=		c c++11

GNU_CONFIGURE=			YES
USE_PKGLOCALEDIR=		YES
USE_LIBTOOL=			YES
USE_TOOLS+=			gmake msgfmt makeinfo perl:build
REPLACE_LOCALEDIR_PATTERNS+=	Make-in
INSTALL_TARGET=			install install-info
TEST_TARGET=			check
INFO_FILES=			yes
CONFIGURE_ENV+=			CONFIG_LDFLAGS=${LDFLAGS:M*:Q}

CONFIGURE_ARGS+=	--disable-binutils
CONFIGURE_ARGS+=	--disable-gprof
CONFIGURE_ARGS+=	--enable-gold
CONFIGURE_ARGS+=	--disable-gas
CONFIGURE_ARGS+=	--disable-ld
#CONFIGURE_ARGS+=	--enable-targets=all
CONFIGURE_ARGS+=	--disable-gdb

CONFIGURE_ARGS+=	--enable-plugins # Required on NetBSD

INSTALL_DIRS=		gold

# In gdb/configure, depcomp is parsed with sed.
SUBST_CLASSES+=			fix-depcomp
SUBST_STAGE.fix-depcomp+=	pre-configure
SUBST_MESSAGE.fix-depcomp+=	Read depcomp directly
SUBST_FILES.fix-depcomp+=	gdb/configure
SUBST_SED.fix-depcomp+=		-e 's,< ./depcomp,${_OVERRIDE_PATH.depcomp},'

AUTO_MKDIRS=		yes

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

# TEST_DEPENDS
#BUILD_DEPENDS+=	dejagnu-[0-9]*:../../devel/dejagnu

#check-base:
#	${RUN}${_ULIMIT_CMD} cd ${TEST_DIRS} && ${TEST_MAKE_CMD} -j1 check TESTS="gdb.base/*.exp"

# Hack to prevent bogus regeneration of files triggered by timestamp delta
# between .c/.h file and the original one like .y
pre-configure:
	${RUN} find ${WRKSRC} -name '*.c' -exec touch {} \;
	${RUN} find ${WRKSRC} -name '*.h' -exec touch {} \;

post-install:
	${RM} -f ${DESTDIR}/${PREFIX}/lib/charset.alias
#
# PATH of libiberty.a differs between clang and gcc: (and conflicts to other toolchain)
# Rename to avoid conflict to native and other toolchain
# and clang differs its path so, (the same as avr-binutils).

	(cd ${DESTDIR}${PREFIX};				\
	for d in ${MACHINE_ARCH}/libiberty.a libiberty.a;	\
	  do if [ -f lib/$$d ]; then				\
		${MV}	lib/$$d	 lib/gdb/libiberty.a;		\
		break;						\
	     fi;						\
	  done;	)

.include "../../wip/mk/git-package.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
