# $NetBSD$

VERSION=	3.0.4
PKGNAME=	fpc-${VERSION}
DISTNAME=	fpc-${VERSION}.source
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freepascal/Source/${VERSION}/}
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=freepascal/Bootstrap/3.0.0/}
DISTFILES=	${DEFAULT_DISTFILES}

MAINTAINER=	js-pkgsrc@nil.im
HOMEPAGE=	https://www.freepascal.org/
COMMENT=	Pascal compiler
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/fpc-${VERSION}
USE_TOOLS+=		gmake

MAKEFLAGS+=	 	PREFIX=${PREFIX} INSTALL_PREFIX=${DESTDIR}${PREFIX}

ONLY_FOR_PLATFORM+=	Darwin-*-x86_64

.if empty(MACHINE_PLATFORM:MDarwin-*-x86_64)
DISTFILES:=	${DISTFILES} x86_64-macosx-10.7-ppcx64.tar.bz2
MAKEFLAGS+=	PP=${WRKDIR}/ppcx64
MAKEFLAGS+=	OPT="-XR/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk"
.endif

.include "../../mk/bsd.pkg.mk"
