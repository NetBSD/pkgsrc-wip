# $NetBSD: Makefile,v 1.4 2007/04/24 09:36:09 emil_s Exp $
#

DISTNAME=		happy-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/happy/dist/${VERSION}/
DISTFILES=		${DISTNAME}.tar.gz
DISTFILES+=		${DISTNAME}-html.tar.gz
DISTFILES+=		happy.ps.gz
SITES.${DISTNAME}-html.tar.gz=	http://www.haskell.org/happy/doc/
SITES.happy.ps.gz=		http://www.haskell.org/happy/doc/ps/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.haskell.org/happy/dist/
COMMENT=		LALR(1) parser generator for the functional language Haskell

VERSION=		1.16

WRKSRC=			${WRKDIR}/happy-${VERSION}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake perl


DOCDIR=		${PREFIX}/share/doc/happy

#DEPENDS+=	cabal-[0-9]*:../../wip/cabal

do-configure:
	cd ${WRKSRC:Q} &&			\
	runhaskell -cpp Setup.lhs configure	\
	  --ghc					\
	  --prefix=${PREFIX:Q}			\
	  --with-compiler=${PREFIX:Q}/bin/ghc	\
	  --with-hc-pkg=${PREFIX:Q}/bin/ghc-pkg

do-build:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs install

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/happy.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/happy/* ${DOCDIR}

.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
