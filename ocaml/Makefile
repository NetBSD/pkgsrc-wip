# $NetBSD: Makefile,v 1.148 2023/04/09 07:28:27 wiz Exp $

# Please do not update to ocaml 5.x without discussion, as the
# consensus is mostly that those versions are not yet baked, and will
# cause hard-to-debug problems.
DISTNAME=	ocaml-5.4.0
CATEGORIES=	lang
# unreliable
#MASTER_SITES=	https://caml.inria.fr/pub/distrib/ocaml-5.2/
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://ocaml.org/
COMMENT=	The latest implementation of the Caml dialect of ML
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=		c
USE_CC_FEATURES+=	c99
USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake
GNU_CONFIGURE=		yes

MAKE_FLAGS+=		INSTALL=${INSTALL:Q}
MAKE_FLAGS+=		INSTALL_DATA=${INSTALL_DATA:Q}
MAKE_FLAGS+=		INSTALL_PROG=${INSTALL_SCRIPT:Q}

# build failure on i386: "../ocamlopt.opt: text relocations"
MKPIE_SUPPORTED=	no

TEST_PROGRAM=		ocamltest
UNLIMIT_RESOURCES=	stacksize

.include "options.mk"
.include "native.mk"

.if ${OCAML_USE_OPT_COMPILER} == "yes"
CONFIGURE_ARGS+=	--enable-native-compiler
BUILD_TARGET=		world.opt
.else
CONFIGURE_ARGS+=	--disable-native-compiler
BUILD_TARGET=		world
.endif

# configure: error: fma does not work, enable emulation with --enable-imprecise-c99-float-ops
.if ${MACHINE_PLATFORM:MNetBSD-*-i386} || \
    ${MACHINE_PLATFORM:MNetBSD-*-earm*}
CONFIGURE_ARGS+=	--enable-imprecise-c99-float-ops
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} && (${OPSYS_VERSION} < 99999)
# fma(3) was added for powerpc between 9.99.98 and 9.99.99
CONFIGURE_ARGS+=	--enable-imprecise-c99-float-ops
.endif

# This is needed because ${WRKSRC}/build/partial-install.sh uses
# $PWD as part of its script.  However, with /bin/sh on SunOS
# (cd work/foo-1.0 && echo $PWD) will show that the value of PWD is
# set before the cd takes place and is then passed down.  So the end
# result is when ./build/partial-install.sh is called, PWD is set
# to /usr/pkgsrc/devel/ocaml instead of ${WRKSRC}.  /bin/ksh, which
# is what ${SH} is on SunOS, doesn't exhibit this behaviour.
.if ${OPSYS} == "SunOS"
INSTALL_MAKE_FLAGS+=	SHELL=${SH:Q}
.endif

.if ${OPSYS} == "Linux"
INSTALL_UNSTRIPPED=	yes
.endif

INSTALLATION_DIRS=	share/doc/ocaml

PRINT_PLIST_AWK+=	{ gsub(/lib\/ocaml\/${PKGMANDIR:S|/|\\/|}/, "lib/ocaml/$${PKGMANDIR}"); }
PRINT_PLIST_AWK+=	{ if (/\.opt$$/) $$0 = "$${PLIST.ocaml-opt}" $$0 }
PRINT_PLIST_AWK+=	{ if (/\.cmx$$/) $$0 = "$${PLIST.ocaml-opt}" $$0 }
PRINT_PLIST_AWK+=	{ if (/^bin\/ocamlopt/) $$0 = "$${PLIST.ocaml-opt}" $$0 }

do-test:
	cd ${WRKSRC} && ${MAKE_PROGRAM} ${TEST_PROGRAM}
	cd ${WRKSRC}/testsuite && ${MAKE_PROGRAM} all

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
	for f in ${DESTDIR}${PREFIX}/lib/ocaml/*.so \
		${DESTDIR}${PREFIX}/lib/ocaml/stublibs/*.so; do \
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
	done
.endif
.PHONY: fix-man-extension
post-install: fix-man-extension
fix-man-extension:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3 && for i in *.3o; do mv $$i $${i%%o}; done

.include "../../archivers/zstd/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
