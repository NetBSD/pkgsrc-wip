# $NetBSD: Makefile,v 1.11 2008/03/10 18:43:31 asau Exp $
#

DISTNAME=	chicken-3.0.0
CATEGORIES=	lang
MASTER_SITES=	http://chicken.wiki.br/releases/

MAINTAINER=	asau@users.sourceforge.net, airhead@users.sourceforge.net
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake makeinfo
USE_LIBTOOL=	yes
INFO_FILES=	yes
UNLIMIT_RESOURCES=	datasize

# FIXME: is it needed still? (asau)
# Avoid an ICE in gcc2 on sparc64
#CONFIGURE_ENV+=	F77=${FALSE:Q}

OWN_DIRS+=	${PREFIX}/lib/chicken
OWN_DIRS+=	${PREFIX}/lib/chicken/3

.include "../../mk/bsd.prefs.mk"

# PLATFORM detection:
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "DragonFly") || (${OPSYS} == "FreeBSD")
PLATFORM=	bsd
.elif ${OPSYS} == "Linux"
PLATFORM=	linux
.elif ${OPSYS} == "Darwin"
PLATFORM=	macosx
.elif ${OPSYS} == "SunOS"
PLATFORM=	solaris
.else
#PLATFORM+=	${OPSYS} == "Interix"
# possible choices left: mingw-msys mingw cygwin cross-linux-mingw
PKG_FAIL_REASON=	"${OPSYS} is not supported"
.endif

MAKE_ENV+=	HOST=	# fix ${HOST} prepending ${CC}
MAKE_FLAGS+=	PLATFORM=${PLATFORM:Q} PREFIX=${PREFIX:Q} DESTDIR=${DESTDIR:Q}
MAKE_FLAGS+=	TOPMANDIR=${PREFIX:Q}/${PKGMANDIR} INFODIR=${PREFIX:Q}/${PKGINFODIR:Q}
MAKE_FLAGS+=	DOCDIR=${PREFIX:Q}/share/doc/${PKGNAME_NOREV}

INSTALLATION_DIRS+=	share/chicken

BUILD_TARGET=	all chicken.info
TEST_TARGET=	check

.include "../../mk/bsd.pkg.mk"
