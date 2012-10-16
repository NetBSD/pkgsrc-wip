# This file provides default compilation and installation functionality for
# Common Lisp packages.
#
# A package using this file shall define the following variables:
#
#	SHORTNAME
#		Name of the package, prefix "cl-" will be automaticaly ignored
#		respectively replaced by "${COMMON_LISP_SYSTEM}-".
#
#	COMMON_LISP_SYSTEM
#		Defines the system for which this package should be.
#		At the moment only "ecl" is supported, "sbcl" and "clisp" will
#		be supported in the future.
#
# It may define the following variables:
#
#	COMMON_LISP_PACKAGES
#		List of Common Lisp packages provided by this pkgsrc package,
#		default is ${SHORTNAME}.
#
#	COMMON_LISP_EXTRAFILES
#		Defines files which will be copied from ${FILESDIR} to ${WRKSRC},
#               for use with COMMON_LISP_DOCFILES or COMMON_LISP_EXAMPLES.
#
#	COMMON_LISP_DOCFILES
#		Defines files which should be installed to
#		share/doc/<name>.
#
#	COMMON_LISP_EXAMPLES
#		Defines files which should be installed to
#		share/doc/<name>/examples.
#
# For ECL the package should provide folowing files:
#
#	${FILESDIR}/${COMMON_LISP_SYSTEM}-<package>.asd
#		The ASDF file, that should be installed in ECL library path. It
#		will be automatically renamed to "<package>.asd".
#

PKGNAME?=			${LISP_PREFIX}-${SHORTNAME:S/^cl-//}-${VERSION}
COMMON_LISP_SYSTEM?=		unsupported
COMMON_LISP_PACKAGES?=		${SHORTNAME}
COMMON_LISP_DOCFILES?=		# empty
COMMON_LISP_EXAMPLES?=		# empty
USE_LANGUAGES?=			# empty

LISP_PREFIX=			${COMMON_LISP_SYSTEM}
.if !empty(COMMON_LISP_DOCFILES)
INSTALLATION_DIRS+=		share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}
.endif
.if !empty(COMMON_LISP_EXAMPLES)
INSTALLATION_DIRS+=		share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/examples
.endif

.if !empty(COMMON_LISP_SYSTEM:Mecl)
USE_LANGUAGES+=			c
USE_TOOLS+=			install find
ECL_DEFAULT_PACKAGE?=		lang/ecl
ECL_VERSION!=			cd ../../${ECL_DEFAULT_PACKAGE} && ${MAKE} show-var VARNAME=PKGVERSION_NOREV
ECL_CENTRAL_REGISTRY=		lib/ecl-${ECL_VERSION}/
PLIST_SUBST+=			CL_PATH="${ECL_CENTRAL_REGISTRY}"
PLIST_SUBST+=			LISP="${LISP_PREFIX}"
PLIST_SUBST+=			ECL=""
PLIST_SUBST+=			SBCL="@comment "
PLIST_SUBST+=			CLISP="@comment "
PLIST_SUBST+=			CL="@comment "
PLIST_SUBST+=			EXT="fas"
INSTALLATION_DIRS+=		${ECL_CENTRAL_REGISTRY}
DEPENDS+=                       ecl-${ECL_VERSION}{,nb*}:../../${ECL_DEFAULT_PACKAGE}

do-build:
.for pkg in ${COMMON_LISP_PACKAGES}
	( cd ${WRKSRC} && ${PREFIX}/bin/ecl -q -norc \
	    -eval "(format t \"### Build package ~S in directory: ~S~%\" \"${pkg}\" #P\"${WRKSRC}/\")" \
	    -eval "(let ((*load-verbose* nil)) (require 'asdf))" \
	    -eval "(setf asdf:*asdf-verbose* t *compile-verbose* t *load-verbose* t)" \
	    -eval "(setf asdf::*user-cache* \"${WRKSRC}/build/\")" \
	    -eval "(push #P\"${WRKSRC}/\" asdf::*central-registry*)" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${pkg})" \
	    -eval "(quit)" </dev/null )
.endfor
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;
	${FIND} ${WRKSRC} -name 'lib*.a' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
.for pkg in ${COMMON_LISP_PACKAGES}
	${INSTALL_PROGRAM} ${WRKSRC}/build/${pkg}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${pkg}.fas
	${INSTALL_DATA} ${WRKSRC}/build/lib${pkg}.a \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}lib${pkg}.a
	${INSTALL_DATA} ${FILESDIR}/ecl-${pkg:S/^cl-//}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${pkg}.asd
.endfor
.for extra in ${COMMON_LISP_EXTRAFILES}
	${CP} ${FILESDIR}/${extra} ${WRKSRC}/
.endfor
.for doc in ${COMMON_LISP_DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/
.endfor
.for example in ${COMMON_LISP_EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${example} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/examples/
.endfor

.include "../../${ECL_DEFAULT_PACKAGE}/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.else
.if !empty(COMMON_LISP_SYSTEM:Msbcl)
USE_TOOLS+=			install find mkdir
SBCL_DEFAULT_PACKAGE?=		lang/sbcl
SBCL_CENTRAL_REGISTRY=		lib/sbcl/site-systems/
PLIST_SUBST+=			CL_PATH="${SBCL_CENTRAL_REGISTRY}"
PLIST_SUBST+=			LISP="${LISP_PREFIX}"
PLIST_SUBST+=			ECL="@comment "
PLIST_SUBST+=			SBCL=""
PLIST_SUBST+=			CLISP="@comment "
PLIST_SUBST+=			CL=""
PLIST_SUBST+=			EXT="fasl"
INSTALLATION_DIRS+=		${SBCL_CENTRAL_REGISTRY}
DEPENDS+=			sbcl-[0-9]*:../../${SBCL_DEFAULT_PACKAGE}

do-build:
.for pkg in ${COMMON_LISP_PACKAGES}
	( cd ${WRKSRC} && ${PREFIX}/bin/sbcl --no-userinit  \
	    --eval "(format t \"### Build package ~S in directory: ~S~%\" \"${pkg}\" #P\"${WRKSRC}/\")" \
	    --eval "(let ((*load-verbose* nil)) (require 'asdf))" \
	    --eval "(setf asdf:*asdf-verbose* t *compile-verbose* t *load-verbose* t)" \
	    --eval "(setf asdf:*central-registry* '(#P\"${PREFIX}/${SBCL_CENTRAL_REGISTRY}\" #P\"${WRKSRC}/\"))" \
	    --eval "(setf asdf::*user-cache* \"${WRKSRC}/\")" \
	    --eval "(asdf:compile-system :${pkg})" \
	    --non-interactive )
.endfor

do-install:
	( cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} -p ${DESTDIR}${PREFIX}/${SBCL_CENTRAL_REGISTRY}${SHORTNAME}/{} \; )
	( cd ${WRKSRC} && ${FIND} * -type f -exec ${INSTALL_DATA} {} ${DESTDIR}${PREFIX}/${SBCL_CENTRAL_REGISTRY}${SHORTNAME}/{} \; )
.for extra in ${COMMON_LISP_EXTRAFILES}
	${CP} ${FILESDIR}/${extra} ${DESTDIR}${PREFIX}/${SBCL_CENTRAL_REGISTRY}${SHORTNAME}/
.endfor
.for doc in ${COMMON_LISP_DOCFILES}
	${MV} ${DESTDIR}${PREFIX}/${SBCL_CENTRAL_REGISTRY}${SHORTNAME}/${doc} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/
.endfor
.for example in ${COMMON_LISP_EXAMPLES}
	${MV} ${DESTDIR}${PREFIX}/${SBCL_CENTRAL_REGISTRY}${SHORTNAME}/${example} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/examples/
.endfor
	${FIND} -d ${DESTDIR}${PREFIX}/${SBCL_CENTRAL_REGISTRY}${SHORTNAME} -type d -exec ${RMDIR} {} \; >/dev/null 2>&1 || true

.else
.if !empty(COMMON_LISP_SYSTEM:Mclisp)
USE_TOOLS+=			install find mkdir
CLISP_DEFAULT_PACKAGE?=		lang/clisp
CLISP_CENTRAL_REGISTRY=		lib/clisp/asdfmod/
PLIST_SUBST+=			CL_PATH="${CLISP_CENTRAL_REGISTRY}"
PLIST_SUBST+=			LISP="${LISP_PREFIX}"
PLIST_SUBST+=			ECL="@comment "
PLIST_SUBST+=			SBCL="@comment "
PLIST_SUBST+=			CLISP=""
PLIST_SUBST+=			CL=""
PLIST_SUBST+=			EXT="fas"
INSTALLATION_DIRS+=		${CLISP_CENTRAL_REGISTRY}
DEPENDS+=			clisp-[0-9]*:../../${CLISP_DEFAULT_PACKAGE}
DEPENDS+=			clisp-asdf-[0-9]*:../../wip/clisp-asdf

do-build:
.for pkg in ${COMMON_LISP_PACKAGES}
	( cd ${WRKSRC} && ${PREFIX}/bin/clisp -q -norc \
	    -x "(format t \"### Build package ~S in directory: ~S~%\" \"${pkg}\" #P\"${WRKSRC}/\")" \
	    -x "(let ((*load-verbose* nil)) (require \"asdf\"))" \
	    -x "(setf asdf:*asdf-verbose* t *compile-verbose* t *load-verbose* t)" \
	    -x "(setf asdf:*central-registry* '(#P\"${PREFIX}/${CLISP_CENTRAL_REGISTRY}\" #P\"${WRKSRC}/\"))" \
	    -x "(setf asdf::*user-cache* \"${WRKSRC}/\")" \
	    -x "(asdf:compile-system :${pkg})" \
	    -on-error exit )
.endfor

do-install:
	( cd ${WRKSRC} && ${FIND} . -type d -exec ${MKDIR} -p ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME}/{} \; )
	( cd ${WRKSRC} && ${FIND} * -type f ! -name "ASDF-TMP*" -exec ${INSTALL_DATA} {} ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME}/{} \; )
.for extra in ${COMMON_LISP_EXTRAFILES}
	${CP} ${FILESDIR}/${extra} ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME}/
.endfor
.for doc in ${COMMON_LISP_DOCFILES}
	${MV} ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME}/${doc} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/
.endfor
.for example in ${COMMON_LISP_EXAMPLES}
	${MV} ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME}/${example} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/examples/
.endfor
	${FIND} -d ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME} -type d -exec ${RMDIR} {} \; >/dev/null 2>&1 || true

.else
.error "Common Lisp system ${COMMON_LISP_SYSTEM} is not supported."
.endif
.endif
.endif
