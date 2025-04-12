# $NetBSD: Makefile,v 1.1 2021/10/12 08:50:00 dlb Exp $

.include "../../wip/mrust/Makefile.common"

PKGNAME=	mrust-rustclibs-${SNAPSTAMP}
COMMENT=	Rustc libraries & crates compiled using mrust-rustc

DISTFILES=		${DEFAULT_DISTFILES} ${RUSTSRC_DIST}
MRUST_DISTDIR=		${DISTDIR}/${DIST_SUBDIR}
RUSTSRC_LINK=		${DISTDIR}/${DIST_SUBDIR}/${RUSTSRC_DIST}
RUSTC_TARG=		${MACHINE_ARCH}-unknown-${OPSYS:tl}
RUSTC_SRC=		${WRKSRC}/rustc-${RUSTVER}-src
RUSTC_SRC_LIB=		${RUSTC_SRC}/library
RUSTC_SRC_VEND=		${RUSTC_SRC}/vendor
PREFIX_S=		${MR_OUTDIR}prefix-s
LIBDIR_S=		${PREFIX_S}/lib/rustlib/${RUSTC_TARG}/lib
RUSTC_S=		${WRKSRC}/bin/rustc
####BUILD_TARGET=		${PREFIX_S}/lib/rustlib/${RUSTC_TARG}/lib/libstd.rlib
##TEST_TARGET=		test
##TEST_MAKE_FLAGS=	-o bin/mrustc -o LIBS
MAKE_FILE=		run_rustc/Makefile
##MAKE_ENV+=		LD_RUN_PATH=${PREFIX}/lib
MAKE_ENV+=		RUSTC_TARGET=${RUSTC_TARG}-unknown-${OPSYS:tl}
##BUILD_MAKE_FLAGS+=	MINICARGO_FLAGS="-L ${PREFIX}/lib/"

##MAKE_JOBS_SAFE=	no		# DLBFLAG: this may be needed

##UNLIMIT_RESOURCES=	stacksize	# DLBFLAG: stacksize doesn't need to
					# be unlimited, but does seem to
					# need to be higher than the default.
					# The value that worked for me was
					# 14m--but that probably could be
					# tuned (or, simply use this UNLIMIT
					# feature...?).

USE_TOOLS+=		gmake
USE_LANGUAGES+=		c c++14

RUSTBIN=		mrust-rustc
RUSTCLIBS=		${PREFIX}/lib/mrust/rustc

.if ${OPSYS:tl} == "macos" || ${OPSYS:tl} == "windows"
MR_OVERRIDES=		${WRKSRC}/script-overrides/stable-${RUSTVER}-${OPSYS:tl}
.else
MR_OVERRIDES=		${WRKSRC}/script-overrides/stable-${RUSTVER}-linux
.endif

#* (no options yet) *#.include "options.mk"


#
# "De-duplicate" the rust source tarball.
#
# Without the following pre-fetch and pre-extract targets,
# the mrust build infrastructure will needlessly download its
# own, duplicate copy of the rust-lang source tarball into
# distinfo/mrustc.  Instead, this makes a hardlink from the
# canonical location, if the tarball already exists there.
#
pre-fetch:
	[ -e "${MRUST_DISTDIR}" ] || ${MKDIR} "${MRUST_DISTDIR}"
	if [ -e "${DISTDIR}/${RUSTSRC_DIST}" ]; then			\
	    ${LN} -f "${DISTDIR}/${RUSTSRC_DIST}" "${MRUST_DISTDIR}";	\
	fi


#
# Once the checksum is verified, also make the rust source tarball
# available in the expected location for real rust-src builds.
# Note: be certain the checksum for the rust-lang tarball
# in the mrust* distinfo files matches the one in the rust-src
# distinfo files.
#
pre-extract:
	[ -e ${DISTDIR}/${RUSTSRC_DIST} ] ||				\
	    ${LN} ${RUSTSRC_LINK} ${DISTDIR}/


#
# "put" (link?) mrustc & minicargo binaries and libraries into
# directories where minicargo.mk will look for them.
# Could buildlink3 help with this?  (Probably not without changing
# upstream Makefile[s]?)
#
# Extract & patch rustc src into the mrustc staging area
#
pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/run_rustc/${LIBDIR_S}
	for ff in mrustc minicargo; do					\
	    [ -e ${WRKSRC}/bin/$${ff} ] ||				\
		${LN} -s ${PREFIX}/bin/$${ff} ${WRKSRC}/bin;		\
	done
	[ -e ${RUSTC_S} ] ||						\
	    ${LN} -s ${PREFIX}/bin/${RUSTBIN} ${RUSTC_S}
	[ -d ${RUSTC_SRC} ] ||						\
	    ${MV} ${WRKDIR}/rustc-${RUSTVER}-src ${RUSTC_SRC}
##	( cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}  \
##		${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} RUSTCSRC_Q )

do-build:
	( cd ${WRKSRC}/run_rustc;					\
          for targ in std panic_unwind proc_macro; do			\
	    MRUSTC_PATH=${RUSTC_S} minicargo -j ${MAKE_JOBS:U1}		\
	        --vendor-dir ${RUSTC_SRC_VEND}				\
	        --script-overrides ${MR_OVERRIDES}			\
	        --output-dir ${LIBDIR_S}   ${RUSTC_SRC_LIB}/$$targ;	\
	  done; )

do-test:
	( cd ${WRKSRC} &&						\
	    ${PKGSRC_SETENV} ${TEST_ENV} 				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${TEST_MAKE_FLAGS}	\
			${TEST_TARGET} )


####
# The source Makefile doesn't have an "install:" target.
# Use a simplistic workaround here.
# [DLBFLAG:] Lacks support for MS Windows STYLE ".EXE" suffixes.
##
do-install:
	${PKGSRC_SETENV} ${INSTALL_ENV}					\
	    ${INSTALL_LIB_DIR} ${DESTDIR}${RUSTCLIBS}
	( cd ${WRKSRC}/run_rustc/${LIBDIR_S} &&				\
	    for ff in lib*.rlib ; do					\
	        ${PKGSRC_SETENV} ${INSTALL_ENV}                         \
		    ${INSTALL_LIB} $$ff					\
			${DESTDIR}${RUSTCLIBS};				\
	    done )

TOOL_DEPENDS+=	mrust-rustc>=${SNAPSTAMP}:../../wip/mrust-rustc
TOOL_DEPENDS+=	mrust-minicargo>=${SNAPSTAMP}:../../wip/mrust-minicargo

##.include "../../devel/libatomic/buildlink3.mk"
##.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
