# $NetBSD: Makefile,v 1.4 2011/11/25 14:01:31 ddeus Exp $
#

VERSION=        1.0.7
SHORTNAME=	flexi-streams
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/flexi-streams/
COMMENT=        FLEXI-STREAMS - Flexible bivalent streams for Common Lisp
LICENSE=        modified-bsd
DEPENDS+=	${LISP_PREFIX}-trivial-gray-streams-[0-9]*:../../wip/cl-trivial-gray-streams

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	CHANGELOG doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
