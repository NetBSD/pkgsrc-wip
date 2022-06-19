# $NetBSD$

DISTNAME=	vlang-weekly-${VER}
VER=		2022.19
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=vlang/}
GITHUB_PROJECT=	v
GITHUB_TAG=	weekly.${VER}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vlang.io/
COMMENT=	The V Programming Language
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	local=1

# vc is the bootstrap compiler and needs updates along with vlang.
# Search https://github.com/vlang/v/releases for the commit ID that
# corresponds to the release.
# Then search in https://github.com/vlang/vc/commits/master for the
# commit that mentions the abbreviated above commit in its commit
# message.
GITHUB_SUBMODULES+=	vlang vc     a298ad7069f6333ef8ab59a616654fc74e04c847 vc
# tccbin is the dummy branch thirdparty-unknown-unknown and needs no updates.
GITHUB_SUBMODULES+=	vlang tccbin de82a130c282c03eac3ccd442b995a5174e865ec thirdparty/tcc

INSTALLDIR=		${PREFIX}/libexec/vlang
INSTALLATION_DIRS+=	bin

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
	# Remove tests:
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/tests
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/*/tests
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/*/*/tests

do-test:
	cd ${WRKSRC} && ./v test-all

.include "../../mk/bsd.pkg.mk"
