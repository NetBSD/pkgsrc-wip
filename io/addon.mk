# $NetBSD: addon.mk,v 1.2 2008/09/07 16:42:28 milosn Exp $

.include "../../wip/io/version.mk"

DISTNAME=		io-${IO_VERSION}
MASTER_SITES=		${IO_MASTER_SITES}
EXTRACT_SUFX=   	.tar.bz2

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/io

TARGET_DIR= ${PREFIX}/lib/io/addons/${ADDON_NAME}
SRC_DIR= ${WRKSRC}/addons/${ADDON_NAME}

SUBST_CLASSES+=			fix-ab

SUBST_STAGE.fix-ab=		pre-build
SUBST_MESSAGE.fix-ab=		Fixing addonbuilder.
SUBST_FILES.fix-ab=		build/AddonBuilder.io
SUBST_SED.fix-ab=		-e 's,/usr/pkg,${PREFIX},g'
SUBST_SED.fix-ab+=		-e 's,headerSearchPaths := List clone,headerSearchPaths := List clone append("${PREFIX}/include/io"),g'
SUBST_SED.fix-ab+=		-e 's,linkDirPathFlag .. v,linkDirPathFlag .. v .. " ${LINKER_RPATH_FLAG}" .. v,g'


do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/io build.io -a ${ADDON_NAME}

do-install:
	${INSTALL_DATA_DIR} ${TARGET_DIR}
	${INSTALL_DATA_DIR} ${TARGET_DIR}/_build
	if [ -d  ${SRC_DIR}/_build/dll ]; then \
		${CP} -rf ${SRC_DIR}/_build/dll ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/_build/lib ]; then \
		${CP} -rf ${SRC_DIR}/_build/lib ${TARGET_DIR}/_build/; \
	fi
	if [ -d ${SRC_DIR}/io ]; then \
		${CP} -rf ${SRC_DIR}/io ${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/depends ]; then \
		${CP} -f ${SRC_DIR}/depends ${TARGET_DIR}/; \
	fi
	if [ -e ${SRC_DIR}/build.io ]; then \
		${CP} -f ${SRC_DIR}/build.io ${TARGET_DIR}/; \
	fi

.include "../../wip/io-vm/buildlink3.mk"
