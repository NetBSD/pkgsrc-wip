# $NetBSD: Makefile,v 1.7 2012/09/24 18:26:53 asau Exp $
#

VERSION=	0.10.7.1
SHORTNAME=	cffi
DISTNAME=	${SHORTNAME}_${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/cffi/releases/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/cffi/
COMMENT=	The Common Foreign Function Interface for Common Lisp
LICENSE=	public-domain
DEPENDS+=	${LISP_PREFIX}-trivial-features-[0-9]*:../../wip/cl-trivial-features
DEPENDS+=	${LISP_PREFIX}-alexandria-[0-9]*:../../wip/cl-alexandria
DEPENDS+=	${LISP_PREFIX}-babel-[0-9]*:../../wip/cl-babel

WRKSRC=			${WRKDIR}/${DISTNAME}
COMMON_LISP_PACKAGES=	${SHORTNAME} ${SHORTNAME}-grovel ${SHORTNAME}-uffi-compat
COMMON_LISP_DOCFILES:=	README COPYRIGHT HEADER TODO
.for example in gethostname gettimeofday mapping
COMMON_LISP_EXAMPLES:=	${COMMON_LISP_EXAMPLES} examples/${example}.lisp
.endfor

.include "options.mk"
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
