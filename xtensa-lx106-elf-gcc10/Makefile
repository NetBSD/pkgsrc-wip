# $NetBSD: Makefile,v 1.7 2022/06/28 11:31:17 wiz Exp $

# using configure options and sources from
# https://github.com/earlephilhower/esp-quick-toolchain

DISTNAME=		gcc-xtensa${GITHUB_TAG:S/releases\/gcc//}
PKGNAME=		${DISTNAME:C/gcc-xtensa/xtensa-lx106-elf-gcc/}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_GITHUB:=jcmvbkbc/}
GITHUB_PROJECT=		gcc-xtensa
GITHUB_TAG=		releases/gcc-10.3.0

DIST_SUBDIR=		${PKGNAME_NOREV}

# Custom xtensa newlib       
DISTFILES=		${DEFAULT_DISTFILES}
DISTFILES+=		newlib-${NEWLIBVER}.tar.gz
NEWLIBVER=		xtensa-4_0_0-lock-arduino
SITES.newlib-${NEWLIBVER}.tar.gz= -https://github.com/earlephilhower/newlib-xtensa/archive/refs/heads/${NEWLIBVER}.tar.gz

# extra patches
.for _p in \
    gcc-Improve-initialization-of-objects-when-the-initializ.patch \
    gcc-ctype-inline-pgmread.patch \
    gcc-eh-alloc.patch \
    gcc-enable-mforcel32-eh.patch \
    gcc-exception-what-to-pmem.patch \
    gcc-file-shortname.patch \
    gcc-func-sect.patch \
    gcc-int32-is-int.patch \
    gcc-mforce-l32.patch \
    gcc-regex-what-to-pmem.patch \
    gcc-stdcsupp-safe.patch \
    gcc-unwind-safe.patch \
    gcc-xtensa-0001-fix-PR-target-98285.patch \
    gcc-xtensa-0002-rearrange-DI-mode-constant-loading.patch \
    gcc-xtensa-0003-add-optimizations-for-shift-operations.patch \
    gcc-xtensa-0004-implement-bswapsi2-bswapdi2-and-helpers.patch \
    gcc-xtensa-0005-fix-PR-target-102115.patch \
    gcc-xtensa-0006-Fix-non-robust-split-condition-in-define_insn.patch \
    gcc-xtensa-0007-fix-Wformat-diag-warnings.patch \
    gcc-xtensa-0008-Rename-deprecated-extv-extzv-insn-patterns-to.patch \
    gcc-xtensa-0009-Reflect-the-32-bit-Integer-Divide-Option.patch \
    gcc-xtensa-0010-Simplify-EXTUI-instruction-maskimm-validation.patch \
    gcc-xtensa-0011-Make-use-of-IN_RANGE-macro-where-appropriate.patch \
    gcc-xtensa-0012-Fix-instruction-counting-regarding-block-move.patch \
    gcc-xtensa-0013-Add-setmemsi-insn-pattern.patch \
    gcc-xtensa-0014-Improve-bswap-sd-i2-insn-patterns.patch \
    gcc-xtensa-0015-fix-PR-target-105879.patch \
    gcc-xtensa-0016-Implement-bswaphi2-insn-pattern.patch \
    gcc-xtensa-0017-Make-one_cmplsi2-optimizer-friendly.patch \
    gcc-xtensa-0018-Optimize-x-y-to-x-y-y.patch \
    gcc-xtensa-0019-Add-clrsbsi2-insn-pattern.patch \
    gcc-xtensa-0020-Tweak-some-widen-multiplications.patch \
    gcc-xtensa-0021-Consider-the-Loop-Option-when-setmemsi-is-exp.patch \
    gcc-xtensa-0022-Improve-instruction-cost-estimation-and-sugge.patch \
    gcc-xtensa-0023-Improve-constant-synthesis-for-both-integer-a.patch \
    gcc-xtensa-0024-Improve-shift-operations-more.patch \
    gcc-xtensa-0025-Simplify-conditional-branch-move-insn-pattern.patch \
    gcc-xtensa-0026-Make-use-of-BALL-BNALL-instructions.patch \
    gcc-xtensa-0027-Optimize-bitwise-AND-operation-with-some-spec.patch \
    gcc-xtensa-0028-Document-new-mextra-l32r-costs-Xtensa-specifi.patch \
    gcc-xtensa-0029-Add-support-for-sibling-call-optimization.patch \
    gcc-xtensa-0030-Add-some-dedicated-patterns-that-correspond-t.patch \
    gcc-xtensa-0031-Eliminate-unwanted-reg-reg-moves-during-DFmod.patch \
    gcc-xtensa-0032-Eliminate-DS-Cmode-hard-register-clobber-that.patch \
    gcc-xtensa-0033-Defer-storing-integer-constants-into-litpool-.patch \
    gcc-xtensa-0034-Apply-a-few-minor-fixes.patch \
    gcc-xtensa-0035-Fix-RTL-insn-cost-estimation-about-relaxed-MO.patch \
    gcc-xtensa-0036-Fix-buffer-overflow.patch \
    gcc-xtensa-0037-Optimize-integer-constant-addition-that-is-be.patch \
    gcc-xtensa-0038-Minor-fix-for-FP-constant-synthesis.patch \
    gcc-xtensa-0039-constantsynth-Make-try-to-find-shorter-instru.patch \
    gcc-xtensa-0040-Optimize-bitwise-AND-with-imm1-followed-by-br.patch \
    gcc-xtensa-0041-Correct-the-relative-RTX-cost-that-correspond.patch \
    gcc-xtensa-0042-Optimize-bitwise-AND-NOT-with-imm-followed-by.patch \
    gcc-xtensa-0043-Add-RTX-costs-for-if_then_else.patch \
    gcc-xtensa-0044-Fix-conflicting-hard-regno-between-indirect-s.patch \
    gcc-xtensa-0045-Turn-on-fsplit-wide-types-early-by-default.patch \
    gcc-xtensa-0046-Optimize-stack-pointer-updates-in-function-pr.patch \
    gcc-xtensa-0047-Improve-indirect-sibling-call-handling.patch \
    gcc-xtensa-0048-add-static-PIE-support.patch \
    gcc-xtensa-0049-Eliminate-unused-stack-frame-allocation-freei.patch \
    gcc-xtensa-0050-Make-complex-hard-register-clobber-eliminatio.patch \
    gcc-xtensa-0051-constantsynth-Add-new-3-insns-synthesis-patte.patch \
    gcc-xtensa-0052-fix-builtin_apply-return-value.patch \
    gcc-xtensa-0053-implement-MI-thunk-generation-for-call0-API.patch \
    gcc-xtensa-0054-enable-section-anchors-support.patch \
    gcc-xtensa-0055-Prepare-the-transition-from-Reload-to-LRA.patch \
    gcc-xtensa-0056-Make-register-A0-allocable-for-the-CALL0-ABI.patch \
    gcc-xtensa-0057-Fix-out-of-bounds-array-access-in-the-movdi-p.patch \
    gcc-xtensa-0058-Tabify-and-trim-trailing-spaces.patch \
    gcc-xtensa-0059-Clean-up-xtensa_expand_prologue.patch \
    gcc-xtensa-0060-Change-GP_RETURN-_REG_COUNT-to-GP_RETURN_-FIR.patch \
    gcc-xtensa-0061-Generate-density-instructions-in-set_frame_pt.patch \
    gcc-xtensa-0062-use-define_c_enums-instead-of-define_constant.patch \
    gcc-xtensa-0063-Check-DF-availability-before-use.patch \
    gcc-xtensa-0064-use-GP_RETURN_-instead-of-magic-constant.patch \
    gcc-xtensa-0065-Optimize-stack-frame-adjustment-more.patch \
    gcc-xtensa-0066-Optimize-bitwise-splicing-operation.patch \
    gcc-xtensa-0067-Make-instruction-cost-estimation-for-size-mor.patch \
    gcc-xtensa-0068-Tune-btrue-insn-pattern.patch \
    gcc-xtensa-0069-Optimize-ctzsi2-and-ffssi2-a-bit.patch \
    gcc-xtensa-0070-Remove-old-broken-tweak-for-leaf-function.patch \
    gcc-xtensa-0071-Optimize-inversion-of-the-MSB.patch \
    gcc-xtensa-0072-Revise-complex-hard-register-clobber-eliminat.patch \
    gcc-xtensa-0073-Enforce-return-address-saving-when-Og-is-spec.patch \
    gcc-xtensa-0074-fix-PR-target-108876.patch \
    gcc-xtensa-0075-Fix-missing-mode-warnings-in-machine-descript.patch \
    gcc-xtensa-0076-Eliminate-the-use-of-callee-saved-register-th.patch \
    gcc-xtensa-0077-Eliminate-unnecessary-general-purpose-reg-reg.patch
PATCHFILES+= ${_p}
.endfor
PATCH_SITES+= https://raw.githubusercontent.com/earlephilhower/esp-quick-toolchain/master/patches/gcc10.3/

PATCHFILES+= gcc-001-jump-tables-in-text-section-earlephilhower.patch
PATCH_SITES+= https://github.com/earlephilhower/esp-quick-toolchain/raw/master/patches/
PATCH_DIST_STRIP= -p1

MAINTAINER=		bouyer@NetBSD.org
HOMEPAGE=		https://github.com/espressif/gcc
COMMENT=		Cross GCC for Espressif ESP8266 bare metal environment
LICENSE=		gnu-gpl-v2 AND gnu-gpl-v3 AND gnu-lgpl-v2 AND gnu-lgpl-v3

CONFLICTS=	xtensa-lx106-elf-gcc-[0-9]*

DEPENDS+=	xtensa-lx106-elf-binutils-[0-9]*:../../cross/xtensa-lx106-elf-binutils

FILESDIR=	${.CURDIR}/../../cross/xtensa-lx106-elf-binutils/files

GNU_CONFIGURE=		yes
INFO_FILES=		yes
USE_LANGUAGES+=		c c++03
USE_TOOLS+=		bash gmake makeinfo perl

# for http://gcc.gnu.org/bugzilla/show_bug.cgi?id=33549
# use makeinfo from pkgsrc/devel/gtexinfo.
TOOL_DEPENDS+=		gtexinfo>=5.1:../../devel/gtexinfo
_TOOLS_USE_PKGSRC.makeinfo= yes

OBJDIR=			../build
CONFIGURE_DIRS=		${OBJDIR}
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIG_SHELL=		${TOOLS_PATH.bash}
WRAPPER_SHELL=		${TOOLS_PATH.bash}
GNU_CONFIGURE_PREFIX=	${PREFIX}/xtensa-lx106-elf

CONFIGURE_ARGS+=	--target=xtensa-lx106-elf
CONFIGURE_ARGS+=	--disable-shared
CONFIGURE_ARGS+=	--with-newlib
CONFIGURE_ARGS+=	--enable-threads=no
CONFIGURE_ARGS+=	--disable-__cxa_atexit
CONFIGURE_ARGS+=	--disable-libgomp
CONFIGURE_ARGS+=	--disable-libmudflap
CONFIGURE_ARGS+=	--disable-nls
CONFIGURE_ARGS+=	--disable-multilib
CONFIGURE_ARGS+=	--disable-bootstrap
CONFIGURE_ARGS+=	--enable-languages=c,c++
CONFIGURE_ARGS+=	--enable-lto
CONFIGURE_ARGS+=	--enable-static=yes
CONFIGURE_ARGS+=	--disable-libstdcxx-verbose

CHECK_PORTABILITY_SKIP+=	contrib/*

WRKSRC=	${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG:S/\//-/}

post-extract:
	${LN} -s ${WRKDIR}/newlib-xtensa-${NEWLIBVER}/newlib ${WRKSRC}/newlib
	${LN} -s ${WRKDIR}/newlib-xtensa-${NEWLIBVER}/libgloss ${WRKSRC}/libgloss

pre-configure:
	${MKDIR} ${WRKSRC}/${OBJDIR}
	${CP} ${FILESDIR}/xtensa-config.h ${WRKSRC}/include/xtensa-config.h

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
