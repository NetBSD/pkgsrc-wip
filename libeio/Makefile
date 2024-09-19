# $NetBSD: Makefile,v 1.3 2013/09/05 10:42:33 fhajny Exp $
#

DISTNAME=	libeio-4.18
PKGNAME=	${DISTNAME:S/-/-1.0pre/}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/scunningham/libeio/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libeio.html
COMMENT=	Full-featured asynchronous I/O library for C
LICENSE=	2-clause-bsd OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake

WRKSRC=	${WRKDIR}/${PKGBASE}-${DISTNAME}

GNU_CONFIGURE_LIBSUBDIR=	eio
CONFIGURE_ARGS+=		--includedir=${PREFIX}/include/eio

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../mk/bsd.pkg.mk"
