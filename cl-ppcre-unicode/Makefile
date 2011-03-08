# $NetBSD: Makefile,v 1.2 2011/03/08 13:36:33 ddeus Exp $
#

VERSION=        2.0.3
SHORTNAME=	cl-ppcre-unicode
DISTNAME=	${SHORTNAME:S/-unicode$//}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-fad/
COMMENT=        CL-PPCRE-UNICODE is the CL-PPCRE package with Unicode support
LICENSE=        modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}
DEPENDS+=		ecl-ppcre-${VERSION}:../../wip/cl-ppcre
DEPENDS+=		ecl-unicode:../../wip/cl-unicode

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
