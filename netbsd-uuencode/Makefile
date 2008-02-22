# $NetBSD: Makefile,v 1.1 2008/02/22 19:28:58 cheusov Exp $
#

DISTNAME=	netbsd-uuencode-4.0
CATEGORIES=	sysutils textproc
MASTER_SITES=	http://mova.org/~cheusov/pub/netbsd-tools/
#${MASTER_SITE_SOURCEFORGE:=netbsd-tools/}
EXTRACT_SUFX=	.tar.bz2

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${DISTNAME:S/encode/decode/}${EXTRACT_SUFX}

WRKSRC=		${WRKDIR}
BUILD_DIRS=	${DISTNAME} ${DISTNAME:S/encode/decode/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	# none
COMMENT=	NetBSD version of uuencode

#USE_FEATURES=		nbcompat
USE_BSD_MAKEFILE=	yes

MAKE_ENV+=	MKCATPAGES=no

.include "../../mk/bsd.pkg.mk"
