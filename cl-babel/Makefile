# $NetBSD: Makefile,v 1.3 2011/11/25 14:01:30 ddeus Exp $
#

VERSION=        0.3.0
SHORTNAME=	babel
DISTNAME=	${SHORTNAME}_${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/babel/releases/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/Babel
COMMENT=        Babel is a character encoding/decoding library for Common Lisp
LICENSE=        public-domain
DEPENDS+=	${LISP_PREFIX}-alexandria-*:../../wip/cl-alexandria
DEPENDS+=	${LISP_PREFIX}-trivial-features-*:../../wip/cl-trivial-features
DEPENDS+=	${LISP_PREFIX}-trivial-gray-streams-*:../../wip/cl-trivial-gray-streams

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_PACKAGES=	${SHORTNAME} ${SHORTNAME}-streams
COMMON_LISP_DOCFILES=	README COPYRIGHT HEADER NOTES

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
