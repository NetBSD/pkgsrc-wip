# $NetBSD: Makefile,v 1.1.1.1 2011/02/20 10:18:07 ddeus Exp $
#

VERSION=        0.6
SHORTNAME=	trivial-features
DISTNAME=	${SHORTNAME}_${VERSION}
PKGNAME=        ${LISP_PREFIX}-${SHORTNAME}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	http://common-lisp.net/~loliveira/tarballs/trivial-features/

MAINTAINER=     ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://www.cliki.net/trivial-features
COMMENT=        Trivial-features ensures consistent *FEATURES* in Common Lisp
LICENSE=        mit

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
	    -eval "(quit)" </dev/null )
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${SHORTNAME}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${SHORTNAME}.asd
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYRIGHT \
	    ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME}/

.include "../../lang/ecl/buildlink3.mk"

.endif

.include "../../mk/bsd.pkg.mk"
