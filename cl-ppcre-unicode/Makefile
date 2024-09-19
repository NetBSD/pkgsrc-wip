# $NetBSD: Makefile,v 1.5 2012/09/24 18:26:53 asau Exp $
#

VERSION=	2.0.11
SHORTNAME=	cl-ppcre-unicode
DISTNAME=	${SHORTNAME:S/-unicode$//}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	-http://weitz.de/files/cl-ppcre.tar.gz

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-ppcre
COMMENT=	CL-PPCRE-UNICODE is the CL-PPCRE package with Unicode support
LICENSE=	modified-bsd

WRKSRC=			${WRKDIR}/${DISTNAME}-${VERSION}

DEPENDS+=		${LISP_PREFIX}-ppcre-${VERSION}{,nb*}:../../wip/cl-ppcre
DEPENDS+=		${LISP_PREFIX}-unicode-[0-9]*:../../wip/cl-unicode

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
