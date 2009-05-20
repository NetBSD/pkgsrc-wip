# $NetBSD: Makefile,v 1.2 2009/05/20 00:58:43 thomasklausner Exp $
#

DISTNAME=	xmonad-contrib-${VERSION}
PKGREVISION=	1
CATEGORIES=	wm
MASTER_SITES=	http://hackage.haskell.org/packages/archive/xmonad-contrib/${VERSION}/

MAINTAINER=	degroote@netbsd.org
HOMEPAGE=	http://xmonad.org/
COMMENT=	Third party tiling scripts to xmonad

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

VERSION=		0.7


do-configure:
	cd ${WRKSRC} &&	runhaskell -cpp Setup.lhs configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs copy


.include "../../wip/hs-x11-extras/buildlink3.mk"
.include "../../wip/hs-x11/buildlink3.mk"
.include "../../wip/xmonad/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
