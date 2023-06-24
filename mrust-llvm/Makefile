# $NetBSD: Makefile,v 1.1 2021/10/12 08:50:00 dlb Exp $

.include "../../wip/mrust/Makefile.common"

PKGNAME=	mrust-llvm-${SNAPSTAMP}
COMMENT=	Special(?) LLVM build from rustc src

BUILD_TARGET=		rustc-${RUSTVER}-src/build/bin/llvm-config
DISTFILES=		${DEFAULT_DISTFILES} ${RUSTSRC_DIST}
##TEST_TARGET=		rust_tests-libs
##TEST_MAKE_FLAGS=	-o bin/mrustc -o LIBS
MAKE_FILE=		minicargo.mk
MAKE_ENV+=		LD_RUN_PATH=${PREFIX}/lib
MAKE_ENV+=		RUSTC_INSTALL_BINDIR=bin
MAKE_ENV+=		RUSTC_TARGET=${MACHINE_ARCH}-unknown-${OPSYS:tl}
##BUILD_MAKE_FLAGS+=	MINICARGO_FLAGS:="-L ${PREFIX}/lib/"

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

##RUSTBIN=		mrust-rustc


#* (no options yet) *#.include "options.mk"


# "put" (link?) mrustc & minicargo binaries and libraries into
# directories where minicargo.mk will look for them.
# Could buildlink3 help with this?  (Probably not without changing
# upstream Makefile[s]?)
pre-build:
###	for dd in "${WRKSRC}/bin" "${WRKSRC}/${MR_OUTDIR}"; do		\
###		[ -e "$${dd}" ] || ${MKDIR} "$${dd}";			\
###	done
###	for ff in mrustc minicargo; do					\
###	    [ -e "${WRKSRC}/bin/$${ff}" ] ||				\
###		${LN} -s ${PREFIX}/bin/$${ff} "${WRKSRC}/bin";		\
###	done
###	( cd ${PREFIX}/lib/mrust/;					\
###	    for ff in *; do						\
###		[ -e "${WRKSRC}/${MR_OUTDIR}$$ff" ] ||			\
###		    ${LN} -s "${PREFIX}/lib/mrust/$$ff"			\
###			"${WRKSRC}/${MR_OUTDIR}";			\
###	    done; )
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} RUSTCSRC


###pre-test:
###	( cd ${WRKSRC} &&						\
###	    ${PKGSRC_SETENV} ${TEST_ENV} 				\
###		${MAKE_PROGRAM} ${MAKE_FLAGS} ${TEST_MAKE_FLAGS}	\
###			${TEST_TARGET2} )


LLVM_SRC_PFX=	rustc-1.39.0-src/build/

###### include the "/" on PFX
#####LLVM_MISC_PFX=	tools/
#####LLVM_MISC=	llvm-opt-fuzzer/CMakeFiles/llvm-opt-fuzzer.dir/link.txt

# include the "/" on PFX
LLVM_INC_PFX=	include/llvm/
LLVM_INC=	Config/AsmParsers.def	 Config/AsmPrinters.def	\
		Config/Disassemblers.def Config/Targets.def	\
		Config/abi-breaking.h	 Config/llvm-config.h	\
		IR/Attributes.inc	 IR/IntrinsicEnums.inc

# include the "/" on PFX
LLVM_BIN_PFX=	bin/
LLVM_BIN=	llvm-config

# DON'T include the "/" on PFX (libLLVM is part of each file name)
LLVM_LIB_PFX=	lib/libLLVM
LLVM_LIB=	AArch64AsmParser.a  AArch64CodeGen.a  AArch64Desc.a     \
		AArch64Disassembler.a  AArch64Info.a  AArch64Utils.a    \
		ARMAsmParser.a  ARMCodeGen.a  ARMDesc.a  ARMDisassembler.a \
		ARMInfo.a  ARMUtils.a  AggressiveInstCombine.a  Analysis.a \
		AsmParser.a  AsmPrinter.a  BinaryFormat.a  BitReader.a  \
		BitWriter.a  BitstreamReader.a  CodeGen.a  Core.a       \
		DebugInfoCodeView.a  DebugInfoDWARF.a  DebugInfoMSF.a   \
		Demangle.a  GlobalISel.a  IRReader.a  InstCombine.a     \
		Instrumentation.a  LTO.a  Linker.a  MC.a  MCDisassembler.a \
		MCParser.a  ObjCARCOpts.a  Object.a  Passes.a  ProfileData.a \
		Remarks.a  ScalarOpts.a  SelectionDAG.a  Support.a  Target.a \
		TransformUtils.a  Vectorize.a  X86AsmParser.a  X86CodeGen.a \
		X86Desc.a  X86Disassembler.a  X86Info.a  X86Utils.a  ipo.a

LLVM_DIRS=	bin  include/llvm/Config  include/llvm/IR  lib
#####		tools/llvm-opt-fuzzer/CMakeFiles/llvm-opt-fuzzer.dir

STAGE_LLVM=	${DESTDIR}${PREFIX}/lib/mrust/llvm

####
# The source Makefile doesn't have an "install:" target.
# Use a simplistic workaround here.
# [DLBFLAG:] Lacks support for MS Windows style ".EXE" suffixes.
##
do-install:
.for dd in ${LLVM_DIRS}
	${PKGSRC_SETENV} ${INSTALL_ENV}					\
	    ${INSTALL_LIB_DIR} ${STAGE_LLVM}/${dd};
.endfor
	( cd ${WRKSRC}/${LLVM_SRC_PFX} &&				\
	    for ff in ${LLVM_INC}; do					\
		${PKGSRC_SETENV} ${INSTALL_ENV}				\
		    ${INSTALL_DATA} -l h ${LLVM_INC_PFX}$$ff		\
		    ${STAGE_LLVM}/${LLVM_INC_PFX}$$ff;			\
	    done;							\
	    for ff in ${LLVM_BIN}; do					\
		${PKGSRC_SETENV} ${INSTALL_ENV}				\
		    ${INSTALL_PROGRAM} ${LLVM_BIN_PFX}$$ff		\
		    ${STAGE_LLVM}/${LLVM_BIN_PFX}$$ff;			\
	    done;							\
	    for ff in ${LLVM_LIB}; do					\
		${PKGSRC_SETENV} ${INSTALL_ENV}				\
		    ${INSTALL_LIB} -l h ${LLVM_LIB_PFX}$$ff		\
		    ${STAGE_LLVM}/${LLVM_LIB_PFX}$$ff;			\
	    done;							\
	)
#####	    for ff in ${LLVM_MISC}; do					\
#####		${PKGSRC_SETENV} ${INSTALL_ENV}				\
#####		    ${INSTALL_DATA} -l h ${LLVM_MISC_PFX}$$ff		\
#####		    ${STAGE_LLVM}/${LLVM_MISC_PFX}$$ff;			\
#####	    done;							\


###TOOL_DEPENDS+=	mrust-mrustc>=${SNAPSTAMP}:../../wip/mrust-mrustc
###TOOL_DEPENDS+=	mrust-minicargo>=${SNAPSTAMP}:../../wip/mrust-minicargo
###TOOL_DEPENDS+=	mrust-libs>=${SNAPSTAMP}:../../wip/mrust-libs
TOOL_DEPENDS+=	cmake>=3.18.2:../../devel/cmake


###.include "../../devel/libatomic/buildlink3.mk"
###.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
