# $NetBSD: Makefile,v 1.3 2011/11/25 14:01:33 ddeus Exp $
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
COMMON_LISP_DOCFILES=	CHANGELOG doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
