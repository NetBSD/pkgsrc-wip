# $NetBSD: Makefile,v 1.7 2012/09/29 17:05:52 asau Exp $
#

DISTNAME=		haddock-${VERSION}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://www.haskell.org/haddock/
DISTFILES=		haddock-${VERSION}-src.tar.gz
#DISTFILES+=		haddock-html-${VERSION}.tar.gz

MAINTAINER=		esg@sdf.lonestar.org
HOMEPAGE=		http://www.haskell.org/haddock/
COMMENT=		Documentation tool for Haskell

VERSION=		0.8


USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake perl

DOCDIR=			${PREFIX}/share/doc/haddock

do-configure:
	cd ${WRKSRC:Q} && runhaskell Setup.lhs configure                \
	  --ghc								\
	  --prefix=${PREFIX:Q}						\
	  --with-compiler=${PREFIX:Q}/bin/ghc				\
	  --with-hc-pkg=${PREFIX:Q}/bin/ghc-pkg

do-build:
	cd ${WRKSRC:Q} && runhaskell Setup.lhs build

do-install:
	cd ${WRKSRC:Q} && runhaskell Setup.lhs install

.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
