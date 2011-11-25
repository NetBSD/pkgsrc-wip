# $NetBSD: Makefile,v 1.2 2011/11/25 14:01:30 ddeus Exp $
#

VERSION=        0.9.4
SHORTNAME=	anaphora
DISTNAME=	${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/anaphora/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/anaphora/
COMMENT=        Anaphora is the anaphoric macro collection
LICENSE=        public-domain

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_DOCFILES=	LICENSE

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
