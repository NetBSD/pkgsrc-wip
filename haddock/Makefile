# $NetBSD: Makefile,v 1.2 2005/11/17 14:05:34 emil_s Exp $
#

DISTNAME=		haddock-${VERSION}
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/haddock/
DISTFILES=		haddock-${VERSION}-src.tar.gz
DISTFILES+=		haddock-html-${VERSION}.tar.gz

MAINTAINER=		emil@math.su.se
HOMEPAGE=		http://www.haskell.org/haddock/
COMMENT=		Documentation tool for Haskell

VERSION=		0.7

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
