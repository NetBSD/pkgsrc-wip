# $NetBSD: Makefile,v 1.3 2011/11/25 14:01:31 ddeus Exp $
#

VERSION=        2.0.3
SHORTNAME=	cl-ppcre
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-fad/
COMMENT=        CL-PPCRE is a portable regular expression library for Common Lisp
LICENSE=        modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	CHANGELOG doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
