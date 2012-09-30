# $NetBSD: addon.mk,v 1.5 2012/09/30 05:34:21 asau Exp $

.include "../../wip/io/version.mk"

DISTNAME=		io-${IO_VERSION}
MASTER_SITES=		${IO_MASTER_SITES}
EXTRACT_SUFX=   	.tar.bz2

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/io

TARGET_DIR= ${PREFIX}/lib/io/addons/${ADDON_NAME}
SRC_DIR= ${WRKSRC}/addons/${ADDON_NAME}

HEADER_PATHS=	append("${PREFIX}/include/io")
LIB_PATHS=
.for i in ${ADDON_DEPENDS_ON_ADDONS}
HEADER_PATHS+=	append("${PREFIX}/include/io/${i}")
LIB_PATHS+=	append("${PREFIX}/lib/io/addons/${i}/_build/dll")
.endfor

SUBST_CLASSES+=			fix-ab

SUBST_STAGE.fix-ab=		pre-build
SUBST_MESSAGE.fix-ab=		Fixing addonbuilder.
SUBST_FILES.fix-ab=		build/AddonBuilder.io
SUBST_SED.fix-ab=		-e 's,/usr/pkg,${PREFIX},g'
SUBST_SED.fix-ab+=		-e 's,headerSearchPaths := List clone,headerSearchPaths := List clone ${HEADER_PATHS},g'
SUBST_SED.fix-ab+=		-e 's,libSearchPaths := List clone,libSearchPaths := List clone ${LIB_PATHS},g'
SUBST_SED.fix-ab+=		-e 's,linkDirPathFlag .. v,linkDirPathFlag .. v .. " ${LINKER_RPATH_FLAG}" .. v,g'
SUBST_SED.fix-ab+=		-e 's,^.*--rpath -Wl.*$$,nil,g'


do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/io build.io -a ${ADDON_NAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${TARGET_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${TARGET_DIR}/_build
	if [ -d  ${SRC_DIR}/_build/dll ]; then \
		${CP} -rf ${SRC_DIR}/_build/dll ${DESTDIR}${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/_build/lib ]; then \
		${CP} -rf ${SRC_DIR}/_build/lib ${DESTDIR}${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/io ]; then \
		${CP} -rf ${SRC_DIR}/io ${DESTDIR}${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/depends ]; then \
		${CP} -f ${SRC_DIR}/depends ${DESTDIR}${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/protos ]; then \
		${CP} -f ${SRC_DIR}/protos ${DESTDIR}${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/build.io ]; then \
		${CP} -f ${SRC_DIR}/build.io ${DESTDIR}${TARGET_DIR}/; \
	fi
	if [ ! -z "${ADDON_INSTALL_HEADERS}" ]; then \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/io/${ADDON_NAME}; \
		${CP} -f ${SRC_DIR}/source/*.h ${DESTDIR}${PREFIX}/include/io/${ADDON_NAME}/; \
	fi

.include "../../wip/io-vm/buildlink3.mk"
.for i in ${ADDON_DEPENDS_ON_ADDONS}
.include "../../wip/io-${i:tl}/buildlink3.mk"
.endfor
