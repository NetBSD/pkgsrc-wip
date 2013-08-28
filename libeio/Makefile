# $NetBSD: Makefile,v 1.1 2013/08/28 09:02:29 fhajny Exp $
#

DISTNAME=	libeio-4.18
CATEGORIES=	devel
MASTER_SITES=	https://github.com/scunningham/libeio/archive/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://software.schmorp.de/pkg/libeio.html
COMMENT=	Full-featured asynchronous I/O library for C
LICENSE=	2-clause-bsd OR gnu-gpl-v2

# Also installs libeio.la
CONFLICTS+=	eio-[0-9]*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake

WRKSRC=	${WRKDIR}/${PKGBASE}-${DISTNAME}

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../mk/bsd.pkg.mk"
