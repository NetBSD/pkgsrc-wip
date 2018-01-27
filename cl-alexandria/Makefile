# $NetBSD: Makefile,v 1.7 2012/09/24 18:26:53 asau Exp $
#

SHORTNAME=	alexandria
DISTNAME=	${SHORTNAME}-${VERSION}
VERSION=	20120615
PKGNAME=	${LISP_PREFIX}-${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://www.kozachuk.info/netbsd/contrib/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/alexandria/
COMMENT=	Alexandria is a collection utilities for Common Lisp
LICENSE=	public-domain

WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_EXTRAFILES=	alexandria.html
COMMON_LISP_DOCFILES=	README AUTHORS LICENCE alexandria.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
