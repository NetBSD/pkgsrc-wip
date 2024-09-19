# $NetBSD: Makefile,v 1.5 2012/09/24 18:26:53 asau Exp $
#

VERSION=	1.0.7
SHORTNAME=	flexi-streams
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/flexi-streams/
COMMENT=	FLEXI-STREAMS - Flexible bivalent streams for Common Lisp
LICENSE=	modified-bsd
DEPENDS+=	${LISP_PREFIX}-trivial-gray-streams-[0-9]*:../../wip/cl-trivial-gray-streams

WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	CHANGELOG doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
