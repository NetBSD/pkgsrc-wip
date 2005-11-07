# $NetBSD: Makefile,v 1.1.1.1 2005/11/07 16:51:51 emil_s Exp $
#

DISTNAME=		cabal-1.1.3
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/cabal/release/${DISTNAME}/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.haskell.org/cabal/release/${DISTNAME}/
COMMENT=		Haskell common architecture for building applications and libraries

WRKSRC=			${WRKDIR}/cabal

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${PKGDIR}/DEINSTALL

USE_TOOLS+=		gmake
MAKEFILE=		GNUmakefile

GHCVERSION_cmd=		${PREFIX}/bin/ghc -V | ${CUT} -d ' ' -f 8
GHCVERSION=		${GHCVERSION_cmd:sh}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		GHCVERSION=${GHCVERSION}
FILES_SUBST+=		PKGVERSION=${PKGVERSION}
PLIST_SUBST+=		GHCVERSION=${GHCVERSION}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

do-configure:
	cd ${WRKSRC} && ${GMAKE} config

do-build:
	cd ${WRKSRC} && ${GMAKE} build

do-install:
	cd ${WRKSRC} && ${GMAKE} install

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}/pkg-spec-html
	${INSTALL_DATA_DIR} ${DOCDIR}/users-guide
	cd ${WRKSRC}/doc/pkg-spec-html && \
        ${INSTALL_DATA} *.html ${DOCDIR}/pkg-spec-html
	cd ${WRKSRC}/doc/users-guide && \
        ${INSTALL_DATA} *.html ${DOCDIR}/users-guide


.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
