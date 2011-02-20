# $NetBSD: Makefile,v 1.2 2011/02/20 12:05:07 ddeus Exp $
#

VERSION=        0.10.6
SHORTNAME=	cffi
DISTNAME=	${SHORTNAME}_${VERSION}
PKGNAME=        ${LISP_PREFIX}-${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/cffi/releases/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/cffi/
COMMENT=        The Common Foreign Function Interface for Common Lisp
LICENSE=        public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none

.include "options.mk"

.if !empty(PKG_OPTIONS:Mecl)

LISP_PREFIX=			ecl
USE_LANGUAGES+=			c
USE_TOOLS+=			install find mkdir

ECL_VERSION!=                   cd ../../lang/ecl && ${MAKE} show-var VARNAME=PKGVERSION_NOREV
DEPENDS+=                       ecl-${ECL_VERSION}{,nb*}:../../lang/ecl
DEPENDS+=			ecl-trivial-features:../../wip/cl-trivial-features
DEPENDS+=			ecl-alexandria:../../wip/cl-alexandria
DEPENDS+=			ecl-babel:../../wip/cl-babel

ECL_CENTRAL_REGISTRY=           lib/ecl-${ECL_VERSION}/
PLIST_SUBST+=			ECL_PATH="${ECL_CENTRAL_REGISTRY}"
PLIST_SUBST+=			LISP="${LISP_PREFIX}"
INSTALLATION_DIRS+=		${ECL_CENTRAL_REGISTRY}
INSTALLATION_DIRS+=		share/doc/${LISP_PREFIX}-${SHORTNAME}/examples

do-build:
	( cd ${WRKSRC} && ${PREFIX}/bin/ecl -q -norc \
	    -eval "(let ((*load-verbose* nil)) (require 'asdf))" \
	    -eval "(setf asdf::*user-cache* \"${WRKSRC}/build/\")" \
	    -eval "(push #P\"${WRKSRC}/\" asdf::*central-registry*)" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${SHORTNAME})" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${SHORTNAME}-grovel)" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${SHORTNAME}-uffi-compat)" \
	    -eval "(quit)" </dev/null )
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${SHORTNAME}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}.asd
	${INSTALL_PROGRAM} ${WRKSRC}/build/${SHORTNAME}-grovel.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}-grovel.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}-grovel.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}-grovel.asd
	${INSTALL_PROGRAM} ${WRKSRC}/build/${SHORTNAME}-uffi-compat.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}-uffi-compat.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}-uffi-compat.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}-uffi-compat.asd
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYRIGHT \
	    ${WRKSRC}/HEADER ${WRKSRC}/TODO \
	    ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME}/
.for example in gethostname gettimeofday mapping
	${INSTALL_DATA} ${WRKSRC}/examples/${example}.lisp \
	    ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME}/examples/
.endfor

.include "../../lang/ecl/buildlink3.mk"

.endif

.include "../../mk/bsd.pkg.mk"
