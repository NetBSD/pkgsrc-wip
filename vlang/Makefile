# $NetBSD$

#DISTNAME=	vlang-weekly-${VER}
DISTNAME=	vlang-${VER}
#VER=		2023.26
VER=		0.4.8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=vlang/}
GITHUB_PROJECT=	v
#GITHUB_TAG=	weekly.${VER}
GITHUB_TAG=	${VER}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vlang.io/
COMMENT=	The V Programming Language
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	local=1
#MAKE_ENV+=	VFLAGS="-gc none"

DEPENDS+=	boehm-gc>=8:../../devel/boehm-gc

# vc is the bootstrap compiler and needs updates along with vlang.
# Search https://github.com/vlang/v/releases for the commit ID that
# corresponds to the release.
# Then search in https://github.com/vlang/vc/commits/master for the
# commit that mentions the abbreviated above commit in its commit
# message.
GITHUB_SUBMODULES+=	vlang vc     54beb1f416b404a06b894e6883a0e2368d80bc3e vc
# tccbin is the dummy branch thirdparty-unknown-unknown and needs no updates.
GITHUB_SUBMODULES+=	vlang tccbin de82a130c282c03eac3ccd442b995a5174e865ec thirdparty/tcc

INSTALLDIR=		${PREFIX}/libexec/vlang
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	include/vlang
INSTALLATION_DIRS+=	lib/vlang

pre-configure:
	cd ${WRKSRC}/vlib/term/termios && cp termios_freebsd.c.v termios_netbsd.c.v

SUBST_CLASSES+=		hashbang
SUBST_STAGE.hashbang=	pre-install
SUBST_FILES.hashbang+=	cmd/tools/*.vsh
SUBST_FILES.hashbang+=	cmd/tools/*/*.vsh
SUBST_SED.hashbang=	-e '1s,\#!.*,\#!${INSTALLDIR}/v,'

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-install
SUBST_FILES.bash+=	cmd/tools/fuzz/fuzz_v_parser_with_radamsa.sh
SUBST_SED.bash=		-e '1s,\#!.*,\#!${PREFIX}/bin/bash,'

SUBST_CLASSES+=		expect
SUBST_STAGE.expect=	pre-install
SUBST_FILES.expect+=	cmd/tools/vcreate/tests/*.expect
SUBST_SED.expect=	-e '1s,\#!.*,\#!${PREFIX}/bin/expect,'

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-patch
SUBST_FILES.prefix+=	vlib/builtin/builtin_d_gcboehm.c.v
SUBST_VARS.prefix=	PREFIX

# Maybe not all of this is needed, but the upstream simply uses
# the whole source tree.
do-install:
	${MKDIR} ${DESTDIR}${INSTALLDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/v ${DESTDIR}${INSTALLDIR}/
	ln -sf ${INSTALLDIR}/v ${DESTDIR}${PREFIX}/bin/
	cp -r ${WRKSRC}/cmd ${DESTDIR}${INSTALLDIR}
	cp -r ${WRKSRC}/doc ${DESTDIR}${INSTALLDIR}
	cp -r ${WRKSRC}/vlib ${DESTDIR}${INSTALLDIR}
	#cp -r ${WRKSRC}/examples ${DESTDIR}${INSTALLDIR}
	#cp -r ${WRKSRC}/tutorials ${DESTDIR}${INSTALLDIR}
	rm ${DESTDIR}${INSTALLDIR}/vlib/sync/sync_default.c.v.orig
	rm ${DESTDIR}${INSTALLDIR}/vlib/builtin/cfns.c.v.orig
	rm ${DESTDIR}${INSTALLDIR}/vlib/builtin/builtin_d_gcboehm.c.v.orig
	# Remove tests:
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/tests
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/*/tests
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/*/*/tests

do-test:
	cd ${WRKSRC} && ./v test-all

.include "../../mk/bsd.pkg.mk"
