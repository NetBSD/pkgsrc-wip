# $NetBSD$

# Makefile module for producing packages of Pike (primarily internal) modules
.if !defined(PIKE8.0_BUILTIN_MODULE_MK)
PIKE8.0_BUILTIN_MODULE_MK:=

PIKEVERSUFFIX= 	8.0

.include 	"../../lang/pike${PIKEVERSUFFIX}/version.mk"

INTERNAL_MODULENAME?=	${MODULENAME}
MODULE_TYPE?=	module

# if set to yes, build a module modref. most bundled modules already have this included
# in the main pike build, so it's not usually necessary to include a second one.
MAKE_MODREF?=	no

# should the build process check to make sure that the resulting module.so contains 
# some elements? empty modules usually indicate a configure-time problem, so this 
# is a good way to check that all of the libs were found and enabled.
CHECK_MODULE_ENABLED?=	yes

.if (${MODULE_TYPE} != "post_module" && ${MODULE_TYPE} != "module")
.error MODULE_TYPE must be module or post_module
.endif
NAME=		pike${PIKEVERSUFFIX}-${MODULENAME}
PKGNAME=        ${NAME}-${PIKE_VERSION}
DISTNAME=       Pike-v${PIKE_VERSION}

PIKE_EXECUTABLE = pike${PIKEVERSUFFIX}

CHECK_SSP=	no
.if defined(PKGSRC_USE_SSP) 
 # do not add flags to everything 
PKGSRC_USE_SSP= no 
.endif

CATEGORIES=     lang
MASTER_SITES=   http://pike.lysator.liu.se/pub/pike/${PIKE_RELEASE_TYPE}/${PIKE_VERSION}/
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1
MAINTAINER=     william@welliver.org
HOMEPAGE=       http://pike.lysator.liu.se/
COMMENT=        ${MODULENAME} module for Pike ${PIKEVERSUFFIX}

BUILD_DEPENDS+=	 pkgconf-[0-9]*:../../devel/pkgconf
MAKE_JOBS_SAFE= no
USE_TOOLS+=gmake
USE_LANGUAGES=  c c++
SHARED_DOCS_LOC=      ${PREFIX}/share/doc/${NAME}

PIKE_MODULE_SRC=	src/${MODULE_TYPE}s/${INTERNAL_MODULENAME}
PIKE_MODULE_OVERLAPPING_FILES =

SYSTEM_MODULE_PATH!=	pike${PIKEVERSUFFIX} -x module --query=system_module_path
SYSTEM_DOC_PATH=	${PREFIX}/share/pike${PIKEVERSUFFIX}/refdoc

EXTRACT_ELEMENTS+= ${DISTNAME}/src/${MODULE_TYPE}s/${INTERNAL_MODULENAME} ${DISTNAME}/refdoc
FILES_SUBST+=		NAME="${NAME}"
FILES_SUBST+=		MODULENAME="${MODULENAME}"
FILES_SUBST+=		MODULENAME="${INTERNAL_MODULENAME}"
FILES_SUBST+=		PIKEVERSUFFIX="${PIKEVERSUFFIX}"
FILES_SUBST+=		PIKE_EXECUTABLE="${PIKE_EXECUTABLE}"

# remove any dumped modules from the list, as their generation is not deterministic
PRINT_PLIST_AWK+=       /^lib\/.*(\.pike\.o|\.pmod\.o)$$/ { next; }

# add the dumped modules from this build
#GENERATE_PLIST+=	cd ${DESTDIR}/${PREFIX} && find . -name \*.o -print | sed -e 's~^\./~~' ;

do-configure:
	cd ${WRKSRC}/${PIKE_MODULE_SRC} && ${PIKE_EXECUTABLE} -x module --configure
	touch -t 201501010000 ${WRKSRC}/${PIKE_MODULE_SRC}/acconfig.h
	touch ${WRKSRC}/${PIKE_MODULE_SRC}/configure

do-build:
	cd ${WRKSRC}/${PIKE_MODULE_SRC} && ${MAKE_FLAGS} ${PIKE_EXECUTABLE} -x module

# run some build checks and make the module modref if desired.
post-build:
.if(${CHECK_MODULE_ENABLED} != "no")
	cd ${WRKSRC}/${PIKE_MODULE_SRC} && ${PIKE_EXECUTABLE} -e 'return !sizeof(indices(load_module("./module.so"))+indices(load_module("./module.so")()));' || (echo "Module empty, configure problem?" && exit 1)
.endif
.if(${MAKE_MODREF} != "no")
	cd ${WRKSRC}/${PIKE_MODULE_SRC} && ${PIKE_EXECUTABLE} -x module SYSTEM_DOC_PATH=${SYSTEM_DOC_PATH} module_modref
.endif

do-install:
	${MKDIR} ${DESTDIR}${SYSTEM_MODULE_PATH}
	cd ${WRKSRC}/${PIKE_MODULE_SRC} \
	&& SYSTEM_MODULE_PATH=`${PIKE_EXECUTABLE} -x module --query=system_module_path` ${PIKE_EXECUTABLE} -x module SYSTEM_MODULE_PATH=${DESTDIR}${SYSTEM_MODULE_PATH} install

post-install: remove-dumped-modules remove-main-package-files prepare-docs-dir install-shared-docs install-modrefs

# remove files that overlap with files in the main pike package, located under PREFIX
remove-main-package-files:
	cd ${DESTDIR}/${PREFIX} && \
	  if [ "x${PIKE_MODULE_OVERLAPPING_FILES}" != "x" ] ; then \
	    for remove in ${PIKE_MODULE_OVERLAPPING_FILES} ; do \
	      echo removing $${remove} ; \
	      rm $${remove} ; \
	    done ; \
	  fi

remove-dumped-modules:
	cd ${DESTDIR}/${PREFIX}/lib/pike${PIKEVERSUFFIX} && find . -type f | sed -n -e '/\.pmod\.o$$/p' -e '/\.pike\.o$$/p' | xargs -n 20 rm -f

prepare-docs-dir:
	rm -rf ${DESTDIR}/${PREFIX}/doc
	rm -rf ${DESTDIR}/${SHARED_DOCS_LOC}
	${MKDIR} ${DESTDIR}/${SHARED_DOCS_LOC}

install-modrefs:
.if(${MAKE_MODREF} != "no")
	cd ${WRKSRC}/src/${MODULE_TYPE}s/${INTERNAL_MODULENAME} &&  \
	cp -rf refdoc/modref ${DESTDIR}/${SHARED_DOCS_LOC}
.endif

install-shared-docs:
#	cd ${WRKSRC} &&\
#	for x in "${INSTALL_SHARED_DOCS}";  do\
#		${INSTALL_DATA} $$x "${DESTDIR}/${SHARED_DOCS_LOC}"; done

.include "../../lang/pike${PIKEVERSUFFIX}/buildlink3.mk"

.endif #PIKE8.0_BUILTIN_MODULE_MK
