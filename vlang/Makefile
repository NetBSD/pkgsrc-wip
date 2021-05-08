# $NetBSD$

PKGNAME=	vlang-weekly.2021.18
CATEGORIES=	lang
GITHUB_PROJECT=	v
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=vlang/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vlang.io/
COMMENT=	The V Programming Language
LICENSE=	mit

USE_TOOLS+=	gmake

MAKE_FLAGS+=	local=1

GITHUB_SUBMODULES += vlang vc     050e370374c89452d495eac33a75d23f96ed857c vc
GITHUB_SUBMODULES += vlang tccbin de82a130c282c03eac3ccd442b995a5174e865ec thirdparty/tcc

INSTALLDIR=${PREFIX}/libexec/vlang

# Maybe not all of this is needed, but the upstream simply uses
# the whole source tree.
# TODO: the repl wants a writable ${INSTALLDIR}/cmd/tools directory.
# TODO: some tests (${WRKSRC}/v test-all) fail with missing headers
#       and/or libraries.
do-install:
	${MKDIR} ${DESTDIR}${INSTALLDIR}/
	${INSTALL_PROGRAM} ${WRKSRC}/v ${DESTDIR}${INSTALLDIR}/
	${MKDIR} ${DESTDIR}${PREFIX}/bin
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

.include "../../mk/bsd.pkg.mk"
