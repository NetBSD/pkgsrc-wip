# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:54 asau Exp $
#

VERSION=	0.11.1
SHORTNAME=	cl-who
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-who/
COMMENT=	CL-WHO - Yet another Lisp markup language
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	CHANGELOG doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
