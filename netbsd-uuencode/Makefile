# $NetBSD: Makefile,v 1.4 2008/03/07 19:35:15 tnn2 Exp $
#

DISTNAME=	netbsd-uuencode-4.0
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DEFAULT_DISTFILES} ${DISTNAME:S/encode/decode/}${EXTRACT_SUFX}

MAINTAINER=	cheusov@tut.by
COMMENT=	NetBSD version of uuencode and uudecode utils

CONFLICTS+=	gmime-[0-9]*

WRKSRC=		${WRKDIR}
BUILD_DIRS=	${DISTNAME} ${DISTNAME:S/encode/decode/}

HOMEPAGE=	# none

USE_FEATURES=		getprogname setprogname

USE_BSD_MAKEFILE=	yes

MAKE_ENV+=	MKCATPAGES=no

CPPFLAGS+=	-Dlint

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
MAKE_ENV+=	LDADD=-lresolv
.endif

.include "../../mk/bsd.pkg.mk"
