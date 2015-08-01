# $NetBSD: Makefile,v 1.15 2015/08/01 13:58:22 leot1990 Exp $

DISTNAME=	chicken-4.10.0rc4
CATEGORIES=	lang
MASTER_SITES=	http://code.call-cc.org/dev-snapshots/2015/07/24/

MAINTAINER=	asau@inbox.ru #, airhead@users.sourceforge.net
HOMEPAGE=	http://www.call-cc.org/
COMMENT=	Scheme to C compiler, handling R5RS
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=		no

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
UNLIMIT_RESOURCES=	datasize

INSTALLATION_DIRS=	share/chicken
OWN_DIRS=		${PREFIX}/lib/chicken ${PREFIX}/lib/chicken/7

BUILD_TARGET=		all

.include "../../mk/bsd.prefs.mk"

# PLATFORM detection:
.if !empty(OPSYS:M*BSD) || ${OPSYS} == "DragonFly"
PLATFORM=	bsd
.elif ${OPSYS} == "Linux"
PLATFORM=	linux
.elif ${OPSYS} == "Darwin"
PLATFORM=	macosx
.elif ${OPSYS} == "SunOS"
PLATFORM=	solaris
.elif ${OPSYS} == "Haiku"
PLATFORM=	haiku
.else
#PLATFORM+=	${OPSYS} == "Interix"
# possible choices left: mingw-msys mingw cygwin cross-linux-mingw
PKG_FAIL_REASON=	"${OPSYS} is not supported"
.endif

MAKE_FILE=	GNUmakefile
MAKE_ENV+=	C_COMPILER=$(CC:Q)
MAKE_ENV+=	HOST=	# fix ${HOST} prepending ${CC}
MAKE_ENV+=	PLATFORM=${PLATFORM} PREFIX=${PREFIX} DESTDIR=${DESTDIR}
MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	INFODIR=${PREFIX}/${PKGINFODIR}
MAKE_ENV+=	DOCDIR=${PREFIX}/share/doc/${PKGNAME_NOREV}

TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
