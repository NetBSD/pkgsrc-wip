# $NetBSD$

DISTNAME=	libeio-4.18
# eliminate -cvs suffix which cvs-package.mk attaches
PKGNAME=	${DISTNAME}
CATEGORIES=	inputmethod
CVS_ROOT=	:pserver:anonymous:@cvs.schmorp.de/schmorpforge

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libeio.html
COMMENT=	Full-featured asynchronous I/O library for C
LICENSE=	2-clause-bsd OR gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake

GNU_CONFIGURE_LIBSUBDIR=	eio
CONFIGURE_ARGS+=		--includedir=${PREFIX}/include/eio

pre-configure:
	${RUN} cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
