# $NetBSD: Makefile,v 1.1 2014/02/02 14:01:40 makoto Exp $

# The name won't be used for actual fetch, this is cvs version
DISTNAME=	libeio-4.18
# eliminate -cvs suffix which cvs-package.mk attaches
PKGNAME=	libeio-4.18
CATEGORIES=	inputmethod
LICENSE=	2-clause-bsd OR gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.schmorp.de/pkg/libeio.html
COMMENT=	Full-featured asynchronous I/O library for C

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake

WRKSRC=		${WRKDIR}/libeio

GNU_CONFIGURE_LIBSUBDIR=	eio
CONFIGURE_ARGS+=		--includedir=${PREFIX}/include/eio

# password = anoncvs
CVS_ROOT.libeio=	:pserver:anonymous@cvs.schmorp.de/schmorpforge
CVS_REPOSITORIES=	libeio

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
