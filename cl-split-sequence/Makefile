# $NetBSD: Makefile,v 1.3 2012/06/18 12:32:24 ddeus Exp $
#

VERSION=        1.0
SHORTNAME=	split-sequence
DISTNAME=	${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES= 	http://common-lisp.net/~sionescu/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/SPLIT-SEQUENCE
COMMENT=        Common Lisp utility to split sequences
LICENSE=        public-domain

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
