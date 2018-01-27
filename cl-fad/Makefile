# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:53 asau Exp $
#

VERSION=	0.6.4
SHORTNAME=	cl-fad
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-fad/
COMMENT=	CL-FAD is a thin layer atop Common Lisp standard pathname functions
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	README CHANGELOG doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
