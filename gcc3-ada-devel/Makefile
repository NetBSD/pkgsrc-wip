# $NetBSD: Makefile,v 1.4 2003/12/15 18:42:08 johnrshannon Exp $
#

PKGNAME=		gcc3${GCC3_PKGMODIF}-ada-${GCC_VERSION}-devel
COMMENT=		GNU Compiler Collection, version 3-${SNAPDATE}, Ada compiler

.include "../../lang/gcc3-c-devel/buildaddon.mk"

PTHREAD_OPTS+=  require native
CONFIGURE_ARGS+=	--enable-languages="ada"
CONFIGURE_ARGS+=	--enable-threads=yes
CONFIGURE_ARGS+=	--disable-nls

#
# Bootstrap section. Define something to make the pkg usable.
#
# To make things more interesting, we need a gcc with ada support to build
# ada support.
# A gcc tree with compiler driver and gnatbind should be in ADA_BOOT_PATH.
ADA_BOOT_PATH=               /usr/pkg/gcc3bootstrap
# Use this if a special compiler driver is needed to compile ada programs
# (as seen in linux installations).
#GNATGCC_ADA_DRIVER=	gnatgcc

.if defined(ADA_BOOT_PATH)

.if defined(GNATGCC_ADA_DRIVER)
ADA_BOOT_ADAC=	${ADA_BOOT_PATH}/bin/${GNATGCC_ADA_DRIVER}
.else
ADA_BOOT_ADAC=	${ADA_BOOT_PATH}/bin/gcc
.endif

ADA_BOOT_GNATBIND=	${ADA_BOOT_PATH}/bin/gnatbind

EXTRA_ENV+=	ADAC=${ADA_BOOT_ADAC:Q}
CONFIGURE_ENV+=	${EXTRA_ENV}
MAKE_ENV+=	${EXTRA_ENV}

.else # !ADA_BOOT_PATH

# XXX No known system has ada in the main tree.
ONLY_FOR_PLATFORM=	sorry_need_ada_compiler

.endif # ADA_BOOT_PATH

#
# End of bootstrap section
#

post-patch:
	(cd files; \
		${CP} adasignal.c ${WRKSRC}/gcc/ada; \
		${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada; \
		${CP} dummy_pthreads.c ${WRKSRC}/gcc/ada; \
		for i in *.adb *.ads ; do \
		${CP} $$i ${WRKSRC}/gcc/ada; \
	done )

post-buildlink:
	${LN} -sf ${ADA_BOOT_GNATBIND} ${BUILDLINK_DIR}/bin

post-configure:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} configure-host)
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} configure-target)
	${TEST} -f ${WRKSRC}/gcc/ada/Makefile \
	  || ${FALSE} # no ada bootstrap found by configure
	(cd ${WRKSRC}/gcc/ada && ${TOUCH} treeprs.ads [es]info.h nmake.ad[bs])

post-build:
	(cd ${WRKSRC}/gcc/ada && ${MV} targtyps.o targtyps.o.sav)
	(cd ${WRKSRC}/gcc/ada && ${RM} -f *.o *.ali)
	(cd ${WRKSRC}/gcc/ada && ${MV} targtyps.o.sav targtyps.o)
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib_and_tools)
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk
	${ECHO} "ADA_INCLUDE_PATH+=${GCC_ARCHDIR}/adainclude" >> ${WRKDIR}/gcc3.mk

do-test:
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} check-ada)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gnat1 ${GCC_ARCHDIR}
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		ada.install-common install-gnatlib)
	${RM} -f ${GCC_ARCHDIR}/adalib/lib*.so

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/ada.mk

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
