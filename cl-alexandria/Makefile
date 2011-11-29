# $NetBSD: Makefile,v 1.5 2011/11/29 22:54:53 ddeus Exp $
#

SHORTNAME=	alexandria
DISTNAME=	${SHORTNAME}-${VERSION}
VERSION=	20111129
PKGNAME=        ${LISP_PREFIX}-${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.kozachuk.info/netbsd/contrib/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/alexandria/
COMMENT=        Alexandria is a collection utilities for Common Lisp
LICENSE=        public-domain

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_EXTRAFILES= alexandria.html
COMMON_LISP_DOCFILES=	README AUTHORS LICENCE alexandria.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
