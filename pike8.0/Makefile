# $NetBSD$

PIKEVERSUFFIX=	8.0

.include 	"../../lang/pike${PIKEVERSUFFIX}/version.mk"

NAME=		pike${PIKEVERSUFFIX}
PKGNAME=        ${NAME}-${PIKE_VERSION}
DISTNAME=       Pike-v${PIKE_VERSION}

CATEGORIES=     lang
MASTER_SITES=   http://pike.lysator.liu.se/pub/pike/${PIKE_RELEASE_TYPE}/${PIKE_VERSION}/
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1 OR mpl-1.1
#LICENSE+=	gnu-lgpl-v2.1
#LICENSE+=	mpl-v1.1
MAINTAINER=     william@welliver.org
HOMEPAGE=       http://pike.lysator.liu.se/
COMMENT=        Dynamic language with a syntax similar to Java and C

CHECK_SSP=	no
.if defined(PKGSRC_USE_SSP) 
 # do not add flags to everything 
PKGSRC_USE_SSP= no 
.endif

BUILD_DEPENDS+=	 pkgconf-[0-9]*:../../devel/pkgconf
BUILD_DEPENDS+=	 pkg_alternatives-[0-9]*:../../pkgtools/pkg_alternatives
MAKE_JOBS_SAFE= no
GNU_CONFIGURE= yes
CONFIGURE_SCRIPT=	src/configure
#CONFIGURE_ARGS+= --without-machine-code
CFLAGS+=	-O 
BUILD_MAKE_FLAGS+= 
USE_TOOLS+=gmake
USE_LANGUAGES=  c c++

SHARED_DOCS_LOC=      ${PREFIX}/share/doc/${NAME}
INSTALL_SHARED_DOCS=	ANNOUNCE CHANGES COMMITTERS COPYING COPYRIGHT README README-GIT

INSTALL_TARGET_ARGS+=	INSTALLARGS="buildroot='${DESTDIR}' prefix='${PREFIX}' include_prefix='${PREFIX}/include/${NAME}' lib_prefix='${PREFIX}/lib/${NAME}' --verbose --traditional"
INSTALL_TARGET_ARGS+=	buildroot='${DESTDIR}' prefix='${PREFIX}'

.if (defined(ABI))
CONFIGURE_ARGS+= --with-abi=${ABI}
.endif

FILES_SUBST+=		NAME="${NAME}"

REPLACE_INTERPRETER+=   pike
REPLACE.pike.old=	pike
REPLACE.pike.new=	${PREFIX}/bin/pike${PIKEVERSUFFIX}
REPLACE_FILES.pike=	lib/modules/Tools.pmod/Standalone.pmod/cgrep.pike
REPLACE_FILES.pike+=	bin/test_pike.pike
REPLACE_FILES.pike+=	lib/modules/Tools.pmod/Standalone.pmod/test_pike.pike
REPLACE_FILES.pike+=	lib/modules/Tools.pmod/Standalone.pmod/rsif.pike

# remove any dumped modules from the list, as their generation is not deterministic
PRINT_PLIST_AWK+=       /^lib\/.*(\.pike\.o|\.pmod\.o)$$/ { next; }

# add the dumped modules from this build
#GENERATE_PLIST+=	cd ${DESTDIR}/${PREFIX} && find . -name \*.o -print | sed -e 's~^\./~~' ;

# needed to keep make from removing all precompiled cmods because of a patched file.
post-configure:
	touch -t 201501010000 ${WRKSRC}/src/acconfig.h
	cp ${WRKSRC}/src/backend.c ${WRKSRC}/src/backend.cmod.c
	cp ${WRKSRC}/src/builtin.c ${WRKSRC}/src/builtin.cmod.c
	cp ${WRKSRC}/src/iterators.c ${WRKSRC}/src/iterators.cmod.c
	touch ${WRKSRC}/src/backend.c 
	touch ${WRKSRC}/src/builtin.c
	touch ${WRKSRC}/src/iterators.c

do-install:
	cd ${WRKSRC} \
	&& env ${MAKE_ENV} \
	${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} \
	 -f ${MAKE_FILE} \
	${INSTALL_TARGET} ${INSTALL_TARGET_ARGS}

post-build:
	cd ${WRKSRC} &&  \
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	${MAKE_PROGRAM} ${MAKE_FLAGS} \
	-f ${MAKE_FILE} DESTDIR="" DOCTARGET="all" documentation ; \
	${SED} -e 's~${WRKSRC}/smartlink~${PREFIX}/include/${NAME}/smartlink~' < ${WRKSRC}/specs > ${WRKSRC}/specs.tmp
	mv ${WRKSRC}/specs.tmp ${WRKSRC}/specs

post-install: remove-dumped-modules remove-subpackage-modules fix-versioned-filenames prepare-docs-dir install-shared-docs install-modrefs

remove-subpackage-modules:
	cd ${DESTDIR}/${PREFIX}/lib/${NAME}/modules && \
	  rm ___Java.so ___GTK2.so ___Mysql.so ___Fuse.so ____Image_TIFF.so _Image_FreeType.so _Image_SVG.so _Image_WebP.so Gdbm.so Odbc.so

remove-dumped-modules:
	cd ${DESTDIR}/${PREFIX}/lib/${NAME} && find . -type f | sed -n -e '/\.pmod\.o$$/p' -e '/\.pike\.o$$/p' | xargs -n 20 rm -f
	if [ -f ${DESTDIR}/${PREFIX}/include/${NAME}/y.tab.h ] ; then rm ${DESTDIR}/${PREFIX}/include/${NAME}/y.tab.h ; fi

fix-versioned-filenames:
	mv ${DESTDIR}/${PREFIX}/bin/pike ${DESTDIR}/${PREFIX}/bin/${NAME}
	mv ${DESTDIR}/${PREFIX}/bin/pike.syms ${DESTDIR}/${PREFIX}/bin/${NAME}.syms
	if [ -f ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/pike.1 ] ; then \
	  mv ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/pike.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/${NAME}.1 ; \
	elif [ -f ${DESTDIR}/${PREFIX}/share/man/man1/pike.1 ] ; then \
	  mkdir -p ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1 ; \
	  mv ${DESTDIR}/${PREFIX}/share/man/man1/pike.1 ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/${NAME}.1 ; \
	else \
	  exit 1 ; \
	fi

prepare-docs-dir:
	rm -rf ${DESTDIR}/${PREFIX}/doc
	rm -rf ${DESTDIR}/${SHARED_DOCS_LOC}
	mkdir -p ${DESTDIR}/${SHARED_DOCS_LOC}

install-modrefs:
	cd ${WRKSRC} &&  \
	cp -rf refdoc/modref ${DESTDIR}/${SHARED_DOCS_LOC} && \
	cp -rf refdoc/traditional_manual ${DESTDIR}/${SHARED_DOCS_LOC}

install-shared-docs:
	cd ${WRKSRC} &&\
	for x in "${INSTALL_SHARED_DOCS}";  do\
		${INSTALL_DATA} $$x "${DESTDIR}/${SHARED_DOCS_LOC}"; done
	${MKDIR} ${DESTDIR}/${PREFIX}/share/${NAME}/refdoc/src
	cd ${WRKSRC} && cp -rf refdoc/structure ${DESTDIR}/${PREFIX}/share/${NAME}/refdoc/src
	cd ${WRKSRC} && cp -rf refdoc/src_images ${DESTDIR}/${PREFIX}/share/${NAME}/refdoc/src
	cd ${WRKSRC} && cp -rf refdoc/presentation ${DESTDIR}/${PREFIX}/share/${NAME}/refdoc/src
	cd ${WRKSRC} && cp -rf refdoc/Makefile ${DESTDIR}/${PREFIX}/share/${NAME}/refdoc/src

.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

print-vars:
	${ECHO} vars
.for x in ${MAKEVARS}
        ${ECHO} ${x}: ${${x}}
.endfor
