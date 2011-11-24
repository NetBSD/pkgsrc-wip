# $NetBSD: Makefile,v 1.4 2011/11/24 11:31:40 ddeus Exp $
#

VERSION=        0.1.2
SHORTNAME=	cl-unicode
DISTNAME=	${SHORTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-fad/
COMMENT=        CL-UNICODE - A portable Unicode library for Common Lisp
LICENSE=        modified-bsd
DEPENDS+=	ecl-ppcre-[0-9]*:../../wip/cl-ppcre
DEPENDS+=	ecl-flexi-streams-[0-9]*:../../wip/cl-flexi-streams

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
COMMON_LISP_DOCFILES=	${WRKSRC}/CHANGELOG.txt ${WRKSRC}/doc/index.html

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
