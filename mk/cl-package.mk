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

.if !empty(COMMON_LISP_SYSTEM:Mecl)
LISP_PREFIX=			${COMMON_LISP_SYSTEM}
USE_LANGUAGES+=			c
USE_TOOLS+=			install find
ECL_DEFAULT_PACKAGE?=		lang/ecl
ECL_VERSION!=			cd ../../${ECL_DEFAULT_PACKAGE} && ${MAKE} show-var VARNAME=PKGVERSION_NOREV
ECL_CENTRAL_REGISTRY=		lib/ecl-${ECL_VERSION}/
PLIST_SUBST+=			ECL_PATH="${ECL_CENTRAL_REGISTRY}"
PLIST_SUBST+=			LISP="${LISP_PREFIX}"
INSTALLATION_DIRS+=		${ECL_CENTRAL_REGISTRY}
.if !empty(COMMON_LISP_DOCFILES)
INSTALLATION_DIRS+=		share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}
.endif
.if !empty(COMMON_LISP_EXAMPLES)
INSTALLATION_DIRS+=		share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/examples
.endif

do-build:
.for pkg in ${COMMON_LISP_PACKAGES}
	( cd ${WRKSRC} && ${PREFIX}/bin/ecl -q -norc \
	    -eval "(format t \"### Build package ~S in directory: ~S~%\" \"${pkg}\" #P\"${WRKSRC}/\")" \
	    -eval "(let ((*load-verbose* nil)) (require 'asdf))" \
	    -eval "(setf asdf::*user-cache* \"${WRKSRC}/build/\")" \
	    -eval "(push #P\"${WRKSRC}/\" asdf::*central-registry*)" \
	    -eval "(asdf:oos 'asdf:load-fasl-op :${pkg})" \
	    -eval "(quit)" </dev/null )
.endfor
	${FIND} ${WRKSRC} -name '*.fasb' -exec ${CP} {} ${WRKSRC}/build/ \;

do-install:
.for pkg in ${COMMON_LISP_PACKAGES}
	${INSTALL_PROGRAM} ${WRKSRC}/build/${pkg}.fasb \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${pkg}.fas
	${INSTALL_DATA} ${FILESDIR}/ecl-${pkg:S/^cl-//}.asd \
	    ${DESTDIR}${PREFIX}/${ECL_CENTRAL_REGISTRY}${pkg}.asd
.endfor
.for doc in ${COMMON_LISP_DOCFILES}
	${INSTALL_DATA} ${doc} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/
.endfor
.for example in ${COMMON_LISP_EXAMPLES}
	${INSTALL_DATA} ${example} ${DESTDIR}${PREFIX}/share/doc/${LISP_PREFIX}-${SHORTNAME:S/^cl-//}/examples/
.endfor

.include "../../lang/ecl/buildlink3.mk"
.else
.error "Common Lisp system ${COMMON_LISP_SYSTEM} is not supported."
.endif
