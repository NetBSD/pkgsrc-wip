# $NetBSD: Makefile,v 1.4 2005/05/24 10:29:55 rillig Exp $

DISTNAME=	glibc-${VERSION}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=glibc/}
DISTFILES=	glibc-${VERSION}${EXTRACT_SUFX} \
		glibc-linuxthreads-${VERSION}${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libc/libc.html
COMMENT=	GNU C library

VERSION=	2.3.2

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/work
CFLAGS+=	-I${PREFIX}/include

CONFIGURE_SCRIPT=../${DISTNAME}/configure
CONFIGURE_ARGS+=--disable-profile
CONFIGURE_ARGS+=--enable-add-ons=linuxthreads
CONFIGURE_ARGS+=--with-headers=${PREFIX}/include

BUILD_DEPENDS+=	linux-kernel-headers-[0-9]*:../../wip/linux-kernel-headers

post-extract:
	(cd ${WRKDIR} && ${MV} linuxthreads ${WRKDIR}/${DISTNAME})
	(cd ${WRKDIR} && ${MV} linuxthreads_db ${WRKDIR}/${DISTNAME})
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
