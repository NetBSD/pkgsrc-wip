# $NetBSD: Makefile,v 1.2 2011/03/08 13:36:34 ddeus Exp $
#

VERSION=        2008.11.02
SHORTNAME=	trivial-gray-streams
DISTNAME=	${SHORTNAME}-${VERSION:S/./-/g}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/cl-plus-ssl/download/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/trivial-gray-streams
COMMENT=        Trivial-gray-streams is a compatibility layer for Gray streams
LICENSE=        mit

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_DOCFILES=	${WRKSRC}/README ${WRKSRC}/COPYING

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
