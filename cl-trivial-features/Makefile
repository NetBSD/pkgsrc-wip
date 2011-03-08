# $NetBSD: Makefile,v 1.2 2011/03/08 13:36:33 ddeus Exp $
#

VERSION=        0.6
SHORTNAME=	trivial-features
DISTNAME=	${SHORTNAME}_${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/~loliveira/tarballs/trivial-features/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/trivial-features
COMMENT=        Trivial-features ensures consistent *FEATURES* in Common Lisp
LICENSE=        mit

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_DOCFILES=	${WRKSRC}/README ${WRKSRC}/COPYRIGHT

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
