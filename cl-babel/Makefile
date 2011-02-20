# $NetBSD: Makefile,v 1.1.1.1 2011/02/20 10:38:59 ddeus Exp $
#

VERSION=        0.3.0
SHORTNAME=	babel
DISTNAME=	${SHORTNAME}_${VERSION}
PKGNAME=        ${LISP_PREFIX}-${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/babel/releases/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/Babel
COMMENT=        Babel is a character encoding/decoding library for Common Lisp
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
DEPENDS+=			ecl-alexandria-*:../../wip/cl-alexandria
DEPENDS+=			ecl-trivial-features-*:../../wip/cl-trivial-features
DEPENDS+=			ecl-trivial-gray-streams-*:../../wip/cl-trivial-gray-streams

ECL_CENTRAL_REGISTRY=           lib/ecl-${ECL_VERSION}/
PLIST_SUBST+=			ECL_PATH="${ECL_CENTRAL_REGISTRY}"
PLIST_SUBST+=			LISP="${LISP_PREFIX}"
INSTALLATION_DIRS+=		${ECL_CENTRAL_REGISTRY}
INSTALLATION_DIRS+=		share/doc/${LISP_PREFIX}-${SHORTNAME}

do-build:
	( cd ${WRKSRC} && ${PREFIX}/bin/ecl -q -norc \
	    -eval "(let ((*load-verbose* nil)) (require 'asdf))" \
	    -eval "(setf asdf::*user-cache* \"${WRKSRC}/build/\")" \
	    -eval "(push #P\"${WRKSRC}/\" asdf::*central-registry*)" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${SHORTNAME})" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${SHORTNAME}-streams)" \
	    -eval "(quit)" </dev/null )
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${SHORTNAME}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}.fas
	${INSTALL_PROGRAM} ${WRKSRC}/build/${SHORTNAME}-streams.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}-streams.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}.asd
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}-streams.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}-streams.asd
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYRIGHT \
	    ${WRKSRC}/HEADER ${WRKSRC}/NOTES \
	    ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME}/

.include "../../lang/ecl/buildlink3.mk"

.endif

.include "../../mk/bsd.pkg.mk"
