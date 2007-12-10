# $NetBSD: Makefile,v 1.6 2007/12/10 16:43:58 emil_s Exp $
#

DISTNAME=		cabal-1.2.2.0
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/cabal/release/${DISTNAME}/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.haskell.org/cabal/release/${DISTNAME}/
COMMENT=		Haskell common architecture for building applications and libraries

USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile

GHCVERSION_cmd=		${PREFIX}/bin/ghc -V | ${CUT} -d ' ' -f 8
GHCVERSION=		${GHCVERSION_cmd:sh}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		GHCVERSION=${GHCVERSION}
FILES_SUBST+=		PKGVERSION=${PKGVERSION}
PLIST_SUBST+=		GHCVERSION=${GHCVERSION}

CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${PREFIX}/bin/ghc
CONFIGURE_ARGS+=	--with-hc-pkg=${PREFIX}/bin/ghc-pkg
CONFIGURE_ARGS+=	--prefix=${PREFIX}

CHECK_FILES_SKIP+=	lib/ghc-${GHCVERSION}/package.conf.old

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}


do-configure:
	cd ${WRKSRC} &&						\
	${SETENV} ${CONFIGURE_ENV} runhaskell -cpp Setup.lhs configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs install

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/pkg-spec-html
	${INSTALL_DATA_DIR} ${DOCDIR}/users-guide
	cd ${WRKSRC}/doc/pkg-spec-html && \
        ${INSTALL_DATA} *.html ${DOCDIR}/pkg-spec-html
	cd ${WRKSRC}/doc/users-guide && \
        ${INSTALL_DATA} *.html ${DOCDIR}/users-guide


.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
