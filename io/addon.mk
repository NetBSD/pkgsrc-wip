# $NetBSD: addon.mk,v 1.1.1.1 2008/09/06 23:30:19 milosn Exp $

.include "../../wip/io/version.mk"

DISTNAME=		io-${IO_VERSION}
MASTER_SITES=		${IO_MASTER_SITES}
EXTRACT_SUFX=   	.tar.bz2

NO_CONFIGURE=		yes
WRKSRC=			${WRKDIR}/io


SUBST_CLASSES+=			fix-ab

SUBST_STAGE.fix-ab=		pre-build
SUBST_MESSAGE.fix-ab=		Fixing addonbuilder.
SUBST_FILES.fix-ab=		build/AddonBuilder.io
SUBST_SED.fix-ab=		-e 's,/usr/pkg,${PREFIX},g'
SUBST_SED.fix-ab+=		-e 's,headerSearchPaths := List clone,headerSearchPaths := List clone append("${PREFIX}/include/io"),g'
SUBST_SED.fix-ab+=		-e 's,linkDirPathFlag .. v,linkDirPathFlag .. v .. " ${LINKER_RPATH_FLAG}" .. v,g'


#DEPENDS+=			io-vm>=${IO_VERSION}:../../wip/io-vm


do-build:
	cd ${WRKSRC} && ${PREFIX}/bin/io build.io -a ${ADDON_NAME}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/io/addons/${ADDON_NAME}
	${INSTALL_DATA_DIR} ${PREFIX}/lib/io/addons/${ADDON_NAME}/_build
	${CP} -rf ${WRKSRC}/addons/${ADDON_NAME}/_build/dll ${PREFIX}/lib/io/addons/${ADDON_NAME}/_build/
	${CP} -rf ${WRKSRC}/addons/${ADDON_NAME}/_build/lib ${PREFIX}/lib/io/addons/${ADDON_NAME}/_build/
	${CP} -rf ${WRKSRC}/addons/${ADDON_NAME}/io ${PREFIX}/lib/io/addons/${ADDON_NAME}/
	#${CP} -rf ${WRKSRC}/addons/${ADDON_NAME}/protos ${PREFIX}/lib/io/addons/${ADDON_NAME}/
	${CP} -rf ${WRKSRC}/addons/${ADDON_NAME}/depends ${PREFIX}/lib/io/addons/${ADDON_NAME}/
	${CP} -rf ${WRKSRC}/addons/${ADDON_NAME}/build.io ${PREFIX}/lib/io/addons/${ADDON_NAME}/

.include "../../wip/io-vm/buildlink3.mk"
