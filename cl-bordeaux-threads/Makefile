# $NetBSD: Makefile,v 1.1.1.1 2011/02/22 21:17:07 ddeus Exp $
#

VERSION=        0.8.0
SHORTNAME=	bordeaux-threads
DISTNAME=	${SHORTNAME}-${VERSION}
PKGNAME=        ${LISP_PREFIX}-${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/project/bordeaux-threads/releases/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/bordeaux-threads/
COMMENT=        Portable shared-state concurrency for Common Lisp
LICENSE=        public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${SHORTNAME}-${VERSION}
USE_LANGUAGES=	# none

.include "options.mk"

.if !empty(PKG_OPTIONS:Mecl)

LISP_PREFIX=			ecl
USE_LANGUAGES+=			c
USE_TOOLS+=			install find mkdir

ECL_VERSION!=                   cd ../../lang/ecl && ${MAKE} show-var VARNAME=PKGVERSION_NOREV
DEPENDS+=                       ecl-${ECL_VERSION}{,nb*}:../../lang/ecl
DEPENDS+=			ecl-alexandria:../../wip/cl-alexandria

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
	    -eval "(asdf:oos 'asdf:load-fasl-op :${SHORTNAME})" \
	    -eval "(quit)" </dev/null )
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${SHORTNAME}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_PATH}${SHORTNAME}.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_PATH}${SHORTNAME}.asd
	${INSTALL_DATA} \
	    ${WRKSRC}/LICENSE ${WRKSRC}/CONTRIBUTORS \
	    ${WRKSRC}/site/index.html ${WRKSRC}/site/style.css \
	    ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME}/

.include "../../lang/ecl/buildlink3.mk"

.endif

.include "../../mk/bsd.pkg.mk"
