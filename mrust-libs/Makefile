# $NetBSD: Makefile,v 1.1 2021/10/12 08:50:00 dlb Exp $

.include "../../wip/mrust/Makefile.common"

PKGNAME=	mrust-libs-${SNAPSTAMP}
COMMENT=	Rustc libraries & crates built using mrustc toolchain

DISTFILES=		${DEFAULT_DISTFILES} ${RUSTSRC_DIST}
MRUST_DISTDIR=		${DISTDIR}/${DIST_SUBDIR}
RUSTSRC_LINK=		${DISTDIR}/${DIST_SUBDIR}/${RUSTSRC_DIST}
BUILD_TARGET=		LIBS
TEST_TARGET=		test
##TEST_TARGET2=		rust_tests-libs
TEST_MAKE_FLAGS=	-o bin/mrustc -o LIBS
MAKE_FILE=		minicargo.mk
MAKE_ENV+=		LD_RUN_PATH=${PREFIX}/lib
MAKE_ENV+=		RUSTC_TARGET=${MACHINE_ARCH}-unknown-${OPSYS:tl}
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

##	    ${RM} -f "${RUSTSRC_LINK}" && 				\

#
# Once the checksum is verified, also make the rust source tarball
# available in the expected location for real rust-src builds.
# Note: be certain the checksum for the rust-lang tarball
# in the mrust* distinfo files matches the one in the rust-src
# distinfo files.
#
pre-extract:
	[ -e "${DISTDIR}/${RUSTSRC_DIST}" ] ||				\
	    ${LN} "${RUSTSRC_LINK}" "${DISTDIR}/"


#
# "put" (link?) mrustc & minicargo binaries and libraries into
# directories where minicargo.mk will look for them.
# Could buildlink3 help with this?  (Probably not without changing
# upstream Makefile[s]?)
#
# Extract & patch rustc src into the mrustc staging area
#
pre-build:
	[ -e "${WRKSRC}/bin" ] || ${MKDIR} ${WRKSRC}/bin
	for ff in mrustc minicargo; do					\
	    [ -e "${WRKSRC}/bin/$${ff}" ] ||				\
		${LN} -s ${PREFIX}/bin/$${ff} "${WRKSRC}/bin";		\
	done
	( cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}  \
		${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} RUSTCSRC )


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
	    ${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/lib/mrust
	( cd ${WRKSRC}/${MR_OUTDIR} &&					\
	    ${RM} build*_cmd.txt build*_dbg.txt;			\
	    for ff in lib*.rlib lib*.rlib.[ho]* build*.txt; do		\
	        ${PKGSRC_SETENV} ${INSTALL_ENV}                         \
		    ${INSTALL_LIB} $$ff					\
			${DESTDIR}${PREFIX}/lib/mrust;			\
	    done )

##	    for ff in lib*.rlib lib*.rlib.[ho]* *build build*.txt; do	\

TOOL_DEPENDS+=	mrust-mrustc>=${SNAPSTAMP}:../../wip/mrust-mrustc
TOOL_DEPENDS+=	mrust-minicargo>=${SNAPSTAMP}:../../wip/mrust-minicargo

.include "../../devel/libatomic/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
