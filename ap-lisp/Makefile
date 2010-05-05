# $NetBSD: Makefile,v 1.1.1.1 2010/05/05 20:57:45 othyro Exp $
#

DISTNAME=	mod_lisp-2.43
PKGNAME=	${DISTNAME:S/mod_/ap-/}
CATEGORIES=	lang www
MASTER_SITES=	http://www.fractalconcept.com/fcweb/download/
EXTRACT_SUFX=	.c

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.fractalconcept.com/asp/html/mod_lisp.html
COMMENT=	Apache module to easily write web applications in Lisp
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=		c

PKG_APACHE_ACCEPTED=    apache13

do-build:
		cd ${WRKDIR} && \
		${APXS} -c ${DISTNAME}${EXTRACT_SUFX}

do-install:
		cd ${WRKDIR} && \
		${APXS} -i ${DISTNAME}.so

.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
