# $NetBSD: Makefile,v 1.4 2012/10/01 21:43:23 asau Exp $
#

DISTNAME=	jlibtool-1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Libtool replacement from the apache APR, written in C

NO_CONFIGURE=		yes
USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		snprintf

AUTO_MKDIRS=		yes

do-extract:
.if !exists(${WRKSRC})
	${RUN} ${MKDIR} ${WRKSRC}
.endif

.for fn in Makefile jlibtool.c
	${RUN} cp ${FILESDIR}/${fn} ${WRKSRC}
.endfor

.include "../../mk/bsd.pkg.mk"
