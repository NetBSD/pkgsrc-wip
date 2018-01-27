# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:53 asau Exp $
#

VERSION=	0.6
SHORTNAME=	trivial-features
DISTNAME=	${SHORTNAME}_${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/~loliveira/tarballs/trivial-features/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/trivial-features
COMMENT=	Trivial-features ensures consistent *FEATURES* in Common Lisp
LICENSE=	mit

WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_DOCFILES=	README COPYRIGHT

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
