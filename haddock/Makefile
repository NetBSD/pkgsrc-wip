# $NetBSD: Makefile,v 1.1.1.1 2005/11/14 16:28:48 emil_s Exp $
#

DISTNAME=		haddock-0.7-src
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/haddock/
DISTFILES=		haddock-0.7-src.tar.gz
DISTFILES+=		haddock-html-0.7.tar.gz

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.haskell.org/haddock/
COMMENT=		Documentation tool for Haskell

WRKSRC=			${WRKDIR}/haddock-0.7
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

DOCDIR=			${PREFIX}/share/doc/haddock

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	@cd ${WRKDIR}/haddock-html-0.6 && \
		${INSTALL_DATA} *.html *.css ${DOCDIR}

.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
