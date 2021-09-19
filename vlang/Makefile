# $NetBSD$

PKGNAME=	vlang-weekly.2021.37
GITHUB_PROJECT=	v
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	${PKGVERSION_NOREV}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=vlang/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vlang.io/
COMMENT=	The V Programming Language
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FILE=	GNUmakefile
MAKE_FLAGS+=	local=1

# vc is the bootstrap compiler and needs updates along with vlang.
# vc has the corresponding v commit id in its commit msg.
GITHUB_SUBMODULES=	vlang vc     feaf2f53697d1834208390df2d0d375deafd9bbc vc
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
	# Remove tests:
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/tests
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/*/tests
	rm -rf ${DESTDIR}${INSTALLDIR}/vlib/*/*/*/tests

do-test:
	cd ${WRKSRC} && ./v test

.include "../../mk/bsd.pkg.mk"
