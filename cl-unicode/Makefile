# $NetBSD: Makefile,v 1.1.1.1 2011/02/22 16:31:21 ddeus Exp $
#

VERSION=        0.1.1
SHORTNAME=	unicode
DISTNAME=	cl-${SHORTNAME}
PKGNAME=        ${LISP_PREFIX}-${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://weitz.de/files/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://weitz.de/cl-fad/
COMMENT=        CL-UNICODE - A portable Unicode library for Common Lisp
LICENSE=        modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}-${VERSION}
USE_LANGUAGES=	# none

.include "options.mk"

.if !empty(PKG_OPTIONS:Mecl)

LISP_PREFIX=			ecl
USE_LANGUAGES+=			c
USE_TOOLS+=			install find mkdir

ECL_VERSION!=                   cd ../../lang/ecl && ${MAKE} show-var VARNAME=PKGVERSION_NOREV
DEPENDS+=                       ecl-${ECL_VERSION}{,nb*}:../../lang/ecl
DEPENDS+=			ecl-ppcre:../../wip/cl-ppcre
DEPENDS+=			ecl-flexi-streams:../../wip/cl-flexi-streams

ECL_PATH=			lib/ecl-${ECL_VERSION}/
PLIST_SUBST+=			ECL_PATH="${ECL_PATH}"
PLIST_SUBST+=			LISP="${LISP_PREFIX}"
INSTALLATION_DIRS+=		${ECL_PATH}
INSTALLATION_DIRS+=		share/doc/${LISP_PREFIX}-${SHORTNAME}


do-build:
	( cd ${WRKSRC} && ${PREFIX}/bin/ecl -q -norc \
	    -eval "(let ((*load-verbose* nil)) (require 'asdf))" \
	    -eval "(setf asdf::*user-cache* \"${WRKSRC}/build/\")" \
	    -eval "(push #P\"${WRKSRC}/\" asdf::*central-registry*)" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${DISTNAME})" \
	    -eval "(quit)" </dev/null )
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${DISTNAME}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_PATH}${DISTNAME}.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_PATH}${DISTNAME}.asd
	${INSTALL_DATA} \
	    ${WRKSRC}/CHANGELOG.txt ${WRKSRC}/doc/index.html \
	    ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME}/

.include "../../lang/ecl/buildlink3.mk"

.endif

.include "../../mk/bsd.pkg.mk"
