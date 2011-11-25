# $NetBSD: Makefile,v 1.5 2011/11/25 14:01:30 ddeus Exp $
#

VERSION=        0.8.1
SHORTNAME=	bordeaux-threads
DISTNAME=	${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/bordeaux-threads/releases/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/bordeaux-threads/
COMMENT=        Portable shared-state concurrency for Common Lisp
LICENSE=        public-domain
DEPENDS+=	${LISP_PREFIX}-alexandria-[0-9]*:../../wip/cl-alexandria

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${SHORTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	LICENSE CONTRIBUTORS site/index.html site/style.css

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
