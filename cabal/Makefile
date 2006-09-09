# $NetBSD: Makefile,v 1.5 2006/09/09 02:49:32 obache Exp $
#

DISTNAME=		cabal-1.1.4
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/cabal/release/${DISTNAME}/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.haskell.org/cabal/release/${DISTNAME}/
COMMENT=		Haskell common architecture for building applications and libraries

USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile

GHCVERSION_cmd=		${PREFIX}/bin/ghc -V | ${CUT} -d ' ' -f 8
GHCVERSION=		${GHCVERSION_cmd:sh}
FILES_SUBST+=		PREFIX=${PREFIX:Q}
FILES_SUBST+=		GHCVERSION=${GHCVERSION:Q}
FILES_SUBST+=		PKGVERSION=${PKGVERSION:Q}
PLIST_SUBST+=		GHCVERSION=${GHCVERSION:Q}

CHECK_FILES_SKIP+=	lib/ghc-${GHCVERSION}/package.conf.old

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}


do-configure:
	cd ${WRKSRC:Q} &&						\
	runhaskell -cpp Setup.lhs configure					\
	  --ghc								\
	  --prefix=${PREFIX:Q}						\
	  --with-compiler=${PREFIX:Q}/bin/ghc				\
	  --with-hc-pkg=${PREFIX:Q}/bin/ghc-pkg

do-build:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs install

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/pkg-spec-html
	${INSTALL_DATA_DIR} ${DOCDIR}/users-guide
	cd ${WRKSRC}/doc/pkg-spec-html && \
        ${INSTALL_DATA} *.html ${DOCDIR}/pkg-spec-html
	cd ${WRKSRC}/doc/users-guide && \
        ${INSTALL_DATA} *.html ${DOCDIR}/users-guide


.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
