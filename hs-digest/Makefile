# $NetBSD: Makefile,v 1.3 2009/05/14 11:23:10 zecrazytux Exp $

DISTNAME=			digest-0.0.0.5
PKGNAME=			hs-digest-0.0.0.5
CATEGORIES=		lang
MASTER_SITES=	http://hackage.haskell.org/packages/archive/digest/0.0.0.5/

MAINTAINER=		zecrazytux@zecrazytux.net
HOMEPAGE=			http://hackage.haskell.org/cgi-bin/hackage-scripts/package/zip-archive
COMMENT=			Haskell package providing efficient cryptographic hash implementations

CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${PREFIX}/bin/ghc
CONFIGURE_ARGS+=	--with-hc-pkg=${PREFIX}/bin/ghc-pkg
CONFIGURE_ARGS+=	--prefix=${PREFIX}

USE_LANGUAGES= c

do-configure:
	cd ${WRKSRC} &&						\
	${SETENV} ${CONFIGURE_ENV} runhaskell Setup.hs configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && runhaskell Setup.hs build

do-install:
	cd ${WRKSRC} && runhaskell Setup.hs install

.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
