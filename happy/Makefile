# $NetBSD: Makefile,v 1.1.1.1 2005/11/16 10:39:48 emil_s Exp $
#

DISTNAME=		happy-1.15
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/happy/dist/
DISTFILES=		${DISTNAME}-src.tar.gz
DISTFILES+=		${DISTNAME}-html.tar.gz
DISTFILES+=		happy.ps.gz
SITES_${DISTNAME}-html.tar.gz=	http://www.haskell.org/happy/doc/
SITES_happy.ps.gz=		http://www.haskell.org/happy/doc/ps/

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.haskell.org/happy/dist/
COMMENT=		LALR(1) parser generator for the functional language Haskell

WRKSRC=			${WRKDIR}/happy-1.15
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake


DOCDIR=		${PREFIX}/share/doc/happy

#DEPENDS+=	cabal-[0-9]*:../../wip/cabal

pre-build:
	${ECHO} "SRC_HC_OPTS += -ignore-package util" >> ${WRKSRC}/mk/build.mk

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/happy.ps ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/happy/* ${DOCDIR}

.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
