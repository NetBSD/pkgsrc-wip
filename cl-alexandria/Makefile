# $NetBSD: Makefile,v 1.2 2011/03/08 13:36:33 ddeus Exp $
#

SHORTNAME=	alexandria
DISTNAME=	${SHORTNAME}
PKGNAME=        ${LISP_PREFIX}-${SHORTNAME}-${_GIT_PKGVERSION:S/.//g}
PKGREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	# none

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/alexandria/
COMMENT=        Alexandria is a collection utilities for Common Lisp
LICENSE=        public-domain

GIT_REPOSITORIES=   master
GIT_REPO.master=    git://common-lisp.net/projects/alexandria/alexandria.git
GIT_MODULE=	    alexandria

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_DOCFILES=	\
    ${WRKSRC}/README ${WRKSRC}/AUTHORS \
    ${WRKSRC}/LICENSE ${FILESDIR}/alexandria.html

.include "options.mk"
.include "../../wip/mk/git-package.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
