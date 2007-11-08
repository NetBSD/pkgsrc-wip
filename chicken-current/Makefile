# $NetBSD: Makefile,v 1.2 2007/11/08 18:03:46 asau Exp $
#

DISTNAME=	chicken-2.732
CATEGORIES=	lang
MASTER_SITES=	http://chicken.wiki.br/dev-snapshots/2007/11/04/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.call-with-current-continuation.org/chicken.html
COMMENT=	Scheme to C compiler, handling R5RS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake makeinfo
USE_LIBTOOL=	yes
UNLIMIT_RESOURCES=	datasize

# Avoid an ICE in gcc2 on sparc64
#CONFIGURE_ENV+=	F77=${FALSE:Q}

OWN_DIRS+=	${PREFIX}/lib/chicken
OWN_DIRS+=	${PREFIX}/lib/chicken/3

# PLATFORM detection:
PLATFORM=	${"${OPSYS}"=="NetBSD":?bsd:}
PLATFORM+=	${"${OPSYS}"=="DragonFly":?bsd:}
PLATFORM+=	${"${OPSYS}"=="FreeBSD":?bsd:}
PLATFORM+=	${"${OPSYS}"=="Linux":?linux:}
PLATFORM+=	${"${OPSYS}"=="Darwin":?macosx:}
PLATFORM+=	${"${OPSYS}"=="SunOS":?solaris:}
#PLATFORM+=	${"${OPSYS}"=="Interix":?*****:}
# possible choices left: mingw-msys mingw cygwin cross-linux-mingw
# PKG_FAIL_REASON=	"${OPSYS} is not supported"

MAKE_VARS=	PLATFORM=${PLATFORM:Q} PREFIX=${PREFIX:Q} DESTDIR=${DESTDIR:Q}${PREFIX:Q}
MAKE_VARS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/man/man1

do-build:
	cd ${WRKSRC:Q} && ${MAKE_PROGRAM} ${MAKE_VARS}
post-build:
	cd ${WRKSRC:Q} && ${MAKE_PROGRAM} ${MAKE_VARS} chicken.info
do-install:
	cd ${WRKSRC:Q} && ${MAKE_PROGRAM} ${MAKE_VARS} install

.include "../../mk/bsd.pkg.mk"
