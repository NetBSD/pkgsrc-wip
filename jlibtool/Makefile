# $NetBSD: Makefile,v 1.1 2007/12/28 03:56:32 bsadewitz Exp $
#

DISTNAME=	jlibtool-1.4
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Libtool replacement from the apache APR, written in C

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		snprintf

do-extract:
.   if !exists(${WRKSRC})
	${RUN} ${MKDIR} ${WRKSRC}
.   endif

.   for fn in Makefile jlibtool.c
	${RUN} cp ${FILESDIR}/${fn} ${WRKSRC}
.   endfor

.include "../../mk/bsd.pkg.mk"
