# $NetBSD: Makefile,v 1.2 2011/03/08 13:36:34 ddeus Exp $
#

VERSION=        0.11.1
SHORTNAME=	cl-who
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-who/
COMMENT=        CL-WHO - Yet another Lisp markup language
LICENSE=        modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	\
	    ${WRKSRC}/CHANGELOG ${WRKSRC}/doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
