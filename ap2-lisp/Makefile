# $NetBSD: Makefile,v 1.1.1.1 2010/05/05 19:46:58 othyro Exp $
#

DISTNAME=	mod_lisp2-1.2
PKGNAME=	${DISTNAME:S/lisp2/lisp/:S/mod_/ap2-/}
CATEGORIES=	lang www
MASTER_SITES=	http://www.fractalconcept.com/fcweb/download/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fractalconcept.com/asp/html/mod_lisp.html
COMMENT=	Apache2 module to easily write web applications in Lisp
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

#WRKSRC=		${WRKDIR}/mod_lisp2-1.2.c
USE_LANGUAGES=		c

PKG_APACHE_ACCEPTED=    apache2 apache22

do-build:
		cd ${WRKDIR} && \
		${APXS} -c ${DISTNAME}${EXTRACT_SUFX}

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
