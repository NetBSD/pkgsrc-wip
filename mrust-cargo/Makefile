# $NetBSD: Makefile,v 1.1 2021/10/12 08:50:00 dlb Exp $

.include "../../wip/mrust/Makefile.common"

PKGNAME=	mrust-cargo-${SNAPSTAMP}
COMMENT=	Cargo--built from rustc src, using mrustc toolchain
BUILD_TARGET=	${MR_OUTDIR}cargo
DISTFILES=	${DEFAULT_DISTFILES} ${RUSTSRC_DIST}
MAKE_FILE=	minicargo.mk
MAKE_ENV+=	LD_RUN_PATH=${PREFIX}/lib
MAKE_ENV+=	LIBGIT2_SYS_USE_PKG_CONFIG=1
MAKE_ENV+=	OPENSSL_DIR=${SSLBASE:Q}
MAKE_ENV+=	RUSTC_TARGET=${MACHINE_ARCH}-unknown-${OPSYS:tl}

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

CARGOBIN=		mrust-cargo


#* (no options yet) *#.include "options.mk"


# "put" (link?) mrustc & minicargo binaries and libraries into
# directories where minicargo.mk will look for them.
# Could buildlink3 help with this?  (Probably not without changing
# upstream Makefile[s]?)
pre-build:
	for dd in "${WRKSRC}/bin" "${WRKSRC}/${MR_OUTDIR}"; do		\
		[ -e "$${dd}" ] || ${MKDIR} "$${dd}";			\
	done
	for ff in mrustc minicargo; do					\
	    [ -e "${WRKSRC}/bin/$${ff}" ] ||				\
		${LN} -s ${PREFIX}/bin/$${ff} "${WRKSRC}/bin";		\
	done
	( cd ${PREFIX}/lib/mrust/;					\
	    for ff in *; do						\
		[ -e "${WRKSRC}/${MR_OUTDIR}$$ff" ] ||			\
		    ${LN} -s "${PREFIX}/lib/mrust/$$ff"			\
			"${WRKSRC}/${MR_OUTDIR}";			\
	    done; )
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} RUSTCSRC


pre-test:
	( cd ${WRKSRC} &&						\
	    ${PKGSRC_SETENV} ${TEST_ENV} 				\
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${TEST_MAKE_FLAGS}	\
			${TEST_TARGET2} )


####
# The source Makefile doesn't have an "install:" target.
# Use a simplistic workaround here.
# [DLBFLAG:] Lacks support for MS Windows style ".EXE" suffixes.
##
do-install:
	${PKGSRC_SETENV} ${INSTALL_ENV}					\
	    ${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin;
	( cd ${WRKSRC}/${MR_OUTDIR} &&					\
	    ${LN} cargo-build/cargo ${CARGOBIN} &&			\
		${PKGSRC_SETENV} ${INSTALL_ENV}                         \
		    ${INSTALL_PROGRAM} ${CARGOBIN}			\
			${DESTDIR}${PREFIX}/bin )


BUILD_DEPENDS+=		mrust-mrustc>=${SNAPSTAMP}:../../wip/mrust-mrustc
BUILD_DEPENDS+=		mrust-libs>=${SNAPSTAMP}:../../wip/mrust-libs
##BUILD_DEPENDS+=	cmake>=3.18.2:../../devel/cmake


##.include "../../devel/libatomic/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
