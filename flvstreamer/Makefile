# $NetBSD: Makefile,v 1.1 2010/06/10 22:47:43 khorben Exp $

DISTNAME=	flvstreamer-2.1c1
WRKSRC=		${WRKDIR}/flvstreamer
CATEGORIES=	multimedia
MASTER_SITES=	http://www.very-clever.com/download/nongnu/flvstreamer/source/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://savannah.nongnu.org/projects/flvstreamer
COMMENT=	Open source command-line RTMP client

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

MAKE_FLAGS+=	posix
PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
