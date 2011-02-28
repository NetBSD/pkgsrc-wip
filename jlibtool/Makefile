# $NetBSD: Makefile,v 1.3 2011/02/28 14:53:17 thomasklausner Exp $
#

DISTNAME=	jlibtool-1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apr.apache.org/
COMMENT=	Libtool replacement from the apache APR, written in C

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=		yes
USE_BSD_MAKEFILE=	yes
USE_FEATURES+=		snprintf

AUTO_MKDIRS=		yes

do-extract:
.   if !exists(${WRKSRC})
	${RUN} ${MKDIR} ${WRKSRC}
.   endif

.   for fn in Makefile jlibtool.c
	${RUN} cp ${FILESDIR}/${fn} ${WRKSRC}
.   endfor

.include "../../mk/bsd.pkg.mk"
