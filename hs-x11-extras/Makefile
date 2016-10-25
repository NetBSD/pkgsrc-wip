# $NetBSD: Makefile,v 1.7 2014/05/21 21:04:46 szptvlfn Exp $
#

DISTNAME=	X11-extras-${VERSION}
PKGNAME=	hs-x11-extras-${VERSION}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://hackage.haskell.org/packages/archive/X11-extras/${VERSION}/

MAINTAINER=	esg@sdf.lonestar.org
HOMEPAGE=	http://hackage.haskell.org/packages/archive/X11-extras/
COMMENT=	Missing Haskell bindings to the X11 graphics library

GHCVERSION_cmd=		${PREFIX}/bin/ghc -V | ${CUT} -d ' ' -f 8
GHCVERSION=		${GHCVERSION_cmd:sh}
FILES_SUBST+=		PREFIX=${PREFIX}
FILES_SUBST+=		GHCVERSION=${GHCVERSION}
FILES_SUBST+=		PKGVERSION=${VERSION}
FILES_SUBST+=		XINCLUDES=${XINCLUDES}
FILES_SUBST+=		XLIBRARIES=${XLIBRARIES}
PLIST_SUBST+=		GHCVERSION=${GHCVERSION}

CONFIGURE_ARGS+=	--ghc
CONFIGURE_ARGS+=	--with-compiler=${PREFIX}/bin/ghc
CONFIGURE_ARGS+=	--with-hc-pkg=${PREFIX}/bin/ghc-pkg
CONFIGURE_ARGS+=	--prefix=${PREFIX}


.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--configure-option="--x-includes=${XINCLUDES}"
CONFIGURE_ARGS+=	--configure-option="--x-libraries=${XLIBRARIES}"


.if ${X11_TYPE} == "modular"
XINCLUDES=		${X11BASE}/include
XLIBRARIES+=		${X11BASE}/lib
.else
XINCLUDES=		${X11BASE}/include
XLIBRARIES=		${X11BASE}/lib
.endif

CONFIGURE_ARGS+=	--configure-option="--without-xinerama"

CHECK_FILES_SKIP+=	lib/ghc-${GHCVERSION}/package.conf.old

VERSION=		0.4

do-configure:
	cd ${WRKSRC} &&						\
	runhaskell -cpp Setup.lhs configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC} && runhaskell -cpp Setup.lhs copy


.include "../../x11/hs-X11/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
