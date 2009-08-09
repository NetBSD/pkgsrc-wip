# $NetBSD: Makefile,v 1.8 2009/08/09 18:18:43 zul_ Exp $
#

DISTNAME=	xmonad-${VERSION}
CATEGORIES=	wm
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmonad/${VERSION}/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://xmonad.org/
COMMENT=	Minimalist tiling window manager for X

USE_LANGUAGES=	c

GHCVERSION_cmd=		${PREFIX}/bin/ghc -V | ${CUT} -d ' ' -f 8
GHCVERSION=		${GHCVERSION_cmd:sh}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		GHCVERSION=${GHCVERSION}
FILES_SUBST+=		PKGVERSION=${VERSION}
PLIST_SUBST+=		GHCVERSION=${GHCVERSION}

CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${PREFIX}/bin/ghc
CONFIGURE_ARGS+=	--with-hc-pkg=${PREFIX}/bin/ghc-pkg
CONFIGURE_ARGS+=	--prefix=${PREFIX}

VERSION=		0.8.1


do-configure:
	cd ${WRKSRC} &&	runhaskell -cpp Setup.lhs configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs copy


.include "../../wip/hs-x11/buildlink3.mk"
.include "../../wip/hs-x11-extras/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
