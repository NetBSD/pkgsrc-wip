# $NetBSD: Makefile,v 1.2 2008/02/22 19:34:31 cheusov Exp $
#

DISTNAME=	netbsd-uuencode-4.0
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${DISTNAME:S/encode/decode/}${EXTRACT_SUFX}

MAINTAINER=	cheusov@tut.by
COMMENT=	NetBSD version of uuencode and uudecode utils

CONFLICTS+=	gmime-[0-9]*

WRKSRC=		${WRKDIR}
BUILD_DIRS=	${DISTNAME} ${DISTNAME:S/encode/decode/}

HOMEPAGE=	# none

#USE_FEATURES=		nbcompat
USE_BSD_MAKEFILE=	yes

MAKE_ENV+=	MKCATPAGES=no

.include "../../mk/bsd.pkg.mk"
