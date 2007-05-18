# $NetBSD: Makefile,v 1.1.1.1 2007/05/18 12:30:20 emil_s Exp $
#

DISTNAME=	X11-extras-${VERSION}
PKGNAME=	hs-x11-extras-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://hackage.haskell.org/packages/archive/X11-extras/

MAINTAINER=	emil@math.su.se
HOMEPAGE=	http://hackage.haskell.org/packages/archive/X11-extras/
COMMENT=	Missing Haskell bindings to the X11 graphics library

#GNU_CONFIGURE=	yes

GHCVERSION_cmd=		${PREFIX}/bin/ghc -V | ${CUT} -d ' ' -f 8
GHCVERSION=		${GHCVERSION_cmd:sh}
FILES_SUBST+=		PREFIX=${PREFIX:Q}
FILES_SUBST+=		GHCVERSION=${GHCVERSION:Q}
FILES_SUBST+=		PKGVERSION=${PKGVERSION:Q}
PLIST_SUBST+=		GHCVERSION=${GHCVERSION:Q}

CHECK_FILES_SKIP+=	lib/ghc-${GHCVERSION}/package.conf.old

VERSION=		0.1

do-configure:
	cd ${WRKSRC:Q} &&						\
        runhaskell -cpp Setup.lhs configure				\
          --ghc								\
          --prefix=${PREFIX:Q}						\
          --with-compiler=${PREFIX:Q}/bin/ghc				\
          --with-hc-pkg=${PREFIX:Q}/bin/ghc-pkg

do-build:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs build

do-install:
	cd ${WRKSRC:Q} && runhaskell -cpp Setup.lhs copy


.include "../../wip/hs-x11/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
