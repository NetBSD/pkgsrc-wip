# $NetBSD$

DISTNAME=	schily-2018-09-04
PKGNAME=	${DISTNAME:S/schily/bosh/}
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://schilytools.sourceforge.net/bosh.html
COMMENT=	The Schily Bourne Shell
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no
MAKE_FLAGS+=	GMAKE_NOWARN=true

USE_TOOLS+=	gmake tbl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# Map PKGSRC_COMPILER to CCOM used by schilytools build system.
.if !empty(PKGSRC_COMPILER:Mgcc)
MAKE_FLAGS+=	CCOM=gcc
.elif !empty(PKGSRC_COMPILER:Mclang)
MAKE_FLAGS+=	CCOM=clang
# The following compilers are untested
.elif !empty(PKGSRC_COMPILER:Micc)
MAKE_FLAGS+=	CCOM=icc
.else
MAKE_FLAGS+=	CCOM=cc
.endif

# Fix testsuite (NetBSD od creates whitespace at the end of output lines)
SUBST_CLASSES+=		od
SUBST_STAGE.od=		post-patch
SUBST_FILES.od=		sh/tests/shelltests/printf/printf.sh
SUBST_SED.od=		-e "s,-e \\\\\"s/\^\[ 	]\*//\\\[\"],-e \\\\\"s/^[ 	]*//\\\\\" -e \\\\\"s/[ 	]*$$//\\\\\",g"
SUBST_MESSAGE.od=	Fix processing of output from od.

do-configure:
	cd ${WRKSRC}/RULES;						\
	if [ ! -f i386-netbsd-clang.rul ]; then				\
		${SED} -e 's/cc-gcc.rul/cc-$$(C_ARCH).rul/' i386-netbsd-gcc.rul >i386-netbsd-clang.rul; \
	fi
	cd ${WRKSRC}/RULES;						\
	for suffix in netbsd-clang.rul netbsd-cc.rul netbsd-gcc.rul; do	\
		if [ ! -f ${MACHINE}-$$suffix ]; then			\
			ln -sf i386-$$suffix ${MACHINE}-$$suffix;	\
		fi;							\
	done;								\
	${CP} -fp i386-darwin-clang.rul x86_64-darwin-clang.rul
	cd ${WRKSRC}/inc && ${MAKE_PROGRAM} ${MAKE_FLAGS}

# The libraries may be split into their own packages to dynamically link them
# (and to share them with other schily tools from this source tree)
do-build:
	cd ${WRKSRC}; for library in					\
		libschily libxtermcap libfind libgetopt libshedit;	\
	do								\
		cd ${WRKSRC}/$${library} &&				\
		${MAKE_PROGRAM} ${MAKE_FLAGS};				\
	done
	cd ${WRKSRC}/sh && ${MAKE_PROGRAM} ${MAKE_FLAGS}

# Process tables in manpage
post-build:
	cd ${WRKSRC}; tbl sh/sh.1 >sh/sh.1.tmp;				\
		mv -f sh/sh.1.tmp sh/bosh.1

do-test:
	cd ${WRKSRC}/sh;						\
	cd tests; ${MAKE_PROGRAM} ${MAKE_FLAGS} tests

do-install:
	cd ${WRKSRC}/sh;						\
		${INSTALL_PROGRAM} ${WRKSRC}/sh/OBJ/*/sh		\
			${DESTDIR}${PREFIX}/bin/bosh;			\
		${INSTALL_MAN} ${WRKSRC}/sh/bosh.1 			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1;		\

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
