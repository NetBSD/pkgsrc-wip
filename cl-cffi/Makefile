# $NetBSD: Makefile,v 1.4 2011/11/24 11:31:40 ddeus Exp $
#

VERSION=        0.10.6
SHORTNAME=	cffi
DISTNAME=	${SHORTNAME}_${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/cffi/releases/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/cffi/
COMMENT=        The Common Foreign Function Interface for Common Lisp
LICENSE=        public-domain
DEPENDS+=	ecl-trivial-features-[0-9]*:../../wip/cl-trivial-features
DEPENDS+=	ecl-alexandria-[0-9]*:../../wip/cl-alexandria
DEPENDS+=	ecl-babel-[0-9]*:../../wip/cl-babel

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_PACKAGES=	${SHORTNAME} ${SHORTNAME}-grovel ${SHORTNAME}-uffi-compat
COMMON_LISP_DOCFILES:=	\
	    ${WRKSRC}/README ${WRKSRC}/COPYRIGHT \
	    ${WRKSRC}/HEADER ${WRKSRC}/TODO
.for example in gethostname gettimeofday mapping
COMMON_LISP_EXAMPLES:=	${COMMON_LISP_EXAMPLES} ${WRKSRC}/examples/${example}.lisp
.endfor

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
