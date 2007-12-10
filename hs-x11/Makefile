# $NetBSD: Makefile,v 1.2 2007/12/10 16:47:42 emil_s Exp $
#

DISTNAME=	X11-${VERSION}
PKGNAME=	hs-x11-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://hackage.haskell.org/packages/archive/X11/${VERSION}/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://hackage.haskell.org/packages/archive/X11/
COMMENT=	Haskell binding to the X11 graphics library

GHCVERSION_cmd=		${PREFIX}/bin/ghc -V | ${CUT} -d ' ' -f 8
GHCVERSION=		${GHCVERSION_cmd:sh}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		GHCVERSION=${GHCVERSION}
FILES_SUBST+=		PKGVERSION=${PKGVERSION}
PLIST_SUBST+=		GHCVERSION=${GHCVERSION}

CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${PREFIX}/bin/ghc
CONFIGURE_ARGS+=	--with-hc-pkg=${PREFIX}/bin/ghc-pkg
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_PREFIX.libX11}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_PREFIX.libX11}/lib


CHECK_FILES_SKIP+=	lib/ghc-${GHCVERSION}/package.conf.old

VERSION=		1.4.0

do-configure:
	cd ${WRKSRC} &&						\
	${SETENV} ${CONFIGURE_ENV} runhaskell -cpp Setup.hs configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && runhaskell -v -cpp Setup.hs build

do-install:
	cd ${WRKSRC} && runhaskell -cpp Setup.hs install


.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
