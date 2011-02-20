# $NetBSD: Makefile,v 1.1.1.1 2011/02/20 10:13:29 ddeus Exp $
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
	    -eval "(asdf:oos 'asdf:load-fasl-op :${DISTNAME})" \
	    -eval "(quit)" </dev/null )
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/${DISTNAME}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${DISTNAME}.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${SHORTNAME}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${DISTNAME}.asd
	${INSTALL_DATA} \
	    ${WRKSRC}/README ${WRKSRC}/AUTHORS ${WRKSRC}/LICENCE \
	    ${FILESDIR}/alexandria.html \
	    ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME}/

.include "../../lang/ecl/buildlink3.mk"

.endif

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
