# $NetBSD: Makefile,v 1.75 2025/04/08 09:33:47 wiz Exp $

DISTNAME=	rust-1.88.0
PKGNAME=	${DISTNAME:S/rust/rust-bin/1}
CATEGORIES=	lang
MASTER_SITES=	https://static.rust-lang.org/dist/
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rust-lang.org/
COMMENT=	Safe, concurrent, practical language (pre-built distribution)
LICENSE=	mit OR apache-2.0

CONFLICTS+=	rust-[0-9]*

# Rust upstream provided binaries
ONLY_FOR_PLATFORM+=	Darwin-*-aarch64
ONLY_FOR_PLATFORM+=	Darwin-*-x86_64
ONLY_FOR_PLATFORM+=	FreeBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-aarch64
ONLY_FOR_PLATFORM+=	Linux-*-i386
ONLY_FOR_PLATFORM+=	Linux-*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-*-x86_64

# he@NetBSD.org provided binaries
ONLY_FOR_PLATFORM+=	NetBSD-*-aarch64
ONLY_FOR_PLATFORM+=	NetBSD-*-aarch64eb
ONLY_FOR_PLATFORM+=	NetBSD-*-earmv7hf
ONLY_FOR_PLATFORM+=	NetBSD-*-earmv6hf
ONLY_FOR_PLATFORM+=	NetBSD-*-i386
ONLY_FOR_PLATFORM+=	NetBSD-*-powerpc
ONLY_FOR_PLATFORM+=	NetBSD-*-sparc64
ONLY_FOR_PLATFORM+=	NetBSD-*-mipsel
ONLY_FOR_PLATFORM+=	NetBSD-*-riscv64

# Illumos, jperkin@ provided binaries
ONLY_FOR_PLATFORM+=	SunOS-*-x86_64

NETBSD_REPO=	https://cdn.NetBSD.org/pub/pkgsrc/distfiles/LOCAL_PORTS/rust/

CHECK_RELRO_SKIP+=	lib/rustlib/*/bin/*

CHECK_SHLIBS_SKIP+=	bin/cargo-clippy
CHECK_SHLIBS_SKIP+=	bin/rustfmt

# Bootstraps built for 9.0 or newer, -8 gcc is too old...
BROKEN_ON_PLATFORM+=	NetBSD-8.*

# Binary distributions aren't built as PIE.
MKPIE_SUPPORTED=	no

NO_BUILD=	yes
USE_TOOLS+=	bash pax
WRKSRC=		${WRKDIR}/${DISTFILES:C/.tar.[gx]z//}

GENERATE_PLIST+=	find ${DESTDIR}${PREFIX} \( -type f -o -type l \) -print | \
			sed 's,${DESTDIR}${PREFIX}/,,' | ${SORT} ;

INSTALLATION_DIRS=	bin ${PKGMANDIR} share/doc/cargo/bash_completion.d

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 080000
BROKEN+=		"Bootstrap unavailable for old NetBSD version"
.endif

DISTFILES:=	# empty

# Rust upstream provided binaries

.if ${MACHINE_PLATFORM:MDarwin-*-aarch64} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	aarch64-apple-darwin
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if ${MACHINE_PLATFORM:MDarwin-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-apple-darwin
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if ${MACHINE_PLATFORM:MFreeBSD-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-freebsd
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if ${MACHINE_PLATFORM:MLinux-*-i386} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	i686-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if (${MACHINE_PLATFORM:MLinux-*-aarch64} && !empty(GLIBC_VERSION)) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	aarch64-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if (${MACHINE_PLATFORM:MLinux-*-aarch64} && empty(GLIBC_VERSION)) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	aarch64-unknown-linux-musl
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if (${MACHINE_PLATFORM:MLinux-*-x86_64} && !empty(GLIBC_VERSION)) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-linux-gnu
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if (${MACHINE_PLATFORM:MLinux-*-x86_64} && empty(GLIBC_VERSION)) || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-linux-musl
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	x86_64-unknown-netbsd
DISTFILES:=	${DISTFILES} ${DISTNAME}-${RUST_ARCH}.tar.gz
.endif

# NetBSD provided binaries:

NBSUF=

.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	aarch64-unknown-netbsd
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-aarch64eb} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	aarch64_be-unknown-netbsd
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv6hf} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	armv6-unknown-netbsd-eabihf
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-earmv7hf} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	armv7-unknown-netbsd-eabihf
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-i386} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	i586-unknown-netbsd
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	powerpc-unknown-netbsd
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-sparc64} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	sparc64-unknown-netbsd
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-mipsel} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	mipsel-unknown-netbsd
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif
.if ${MACHINE_PLATFORM:MNetBSD-*-riscv64} || make(distinfo) || make(makesum) || make(mdi)
RUST_ARCH:=	riscv64gc-unknown-netbsd
DN:=		${DISTNAME}${NBSUF}
EXTRACT_SUFX=	.tar.xz
DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
DISTFILES:=	${DISTFILES} ${DF}
SITES.${DF}=	${NETBSD_REPO}
.endif

# Illumos:
#.if ${MACHINE_PLATFORM:MSunOS-*-x86_64} || make(distinfo) || make(makesum) || make(mdi)
#RUST_ARCH:=	x86_64-unknown-illumos
#DN:=		${DISTNAME}
#EXTRACT_SUFX=	.tar.gz
#DF:=		${DN}-${RUST_ARCH}${EXTRACT_SUFX}
#DISTFILES:=	${DISTFILES} ${DF}
#SITES.${DF}=	https://us-central.manta.mnx.io/pkgsrc/public/pkg-bootstraps/
#.endif


# Binary still extracts to plain non-nb'ed directory
WRKSRC:=	${WRKSRC:C/nb[0-9]*//}
WRKSRC:=	${WRKSRC:C/-$//}

do-install:
	cd ${.CURDIR}/files; pax -rw install.sh ${WRKSRC}
	cd ${WRKSRC} && env PKGMANDIR=${PKGMANDIR} bash ./install.sh \
	--destdir=${DESTDIR} --prefix=${PREFIX}
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/rust-llvm-dwp
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/install.log
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/manifest-*
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/uninstall.sh

.if ${OPSYS} == "Darwin"
.PHONY: fix-darwin-install-name
post-install: fix-darwin-install-name
fix-darwin-install-name:
.  for bin in cargo-clippy clippy-driver miri rls rust-analyzer rustc rustdoc rustfmt
	otool -XL ${DESTDIR}${PREFIX}/bin/${bin}			\
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
		    ${DESTDIR}${PREFIX}/bin/${bin};			\
	done
.  endfor
.  for libexec in rust-analyzer-proc-macro-srv
	otool -XL ${DESTDIR}${PREFIX}/libexec/${libexec}		\
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
		    ${DESTDIR}${PREFIX}/libexec/${libexec};		\
	done
.  endfor
.  for bin in lldb lldb-mi llvm-nm llvm-objcopy llvm-objdump 	\
		llvm-profdata llvm-readobj llvm-size llvm-strip
	otool -XL ${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/${bin} \
	    | ${GREP} '@rpath' | while read rpath rest; do		\
		install_name_tool -change $$rpath			\
		    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib/rustlib/${RUST_ARCH}/lib,g'` \
		    ${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/${bin}; \
	done
.  endfor
.  for lib in lib lib/rustlib/${RUST_ARCH}/lib lib/rustlib/${RUST_ARCH}/codegen-backends
	for f in ${DESTDIR}${PREFIX}/${lib}/lib*.dylib; do		\
		[ ! -f $$f ] && continue;				\
		install_name_tool -id `${ECHO} $$f | ${SED} -e 's,${DESTDIR},,g'` $$f; \
		otool -XL $$f | grep '@rpath' | while read rpath rest; do \
			install_name_tool -change $$rpath \
			    `${ECHO} $$rpath | ${SED} -e 's,@rpath,${PREFIX}/lib,g'` \
			    $$f;					\
		done;							\
	done
.  endfor
.else
# Not Darwin:

TOOL_DEPENDS+=		patchelf-[0-9]*:../../devel/patchelf

RUST_LLVM_RPATH=	${PREFIX}/lib
FORCE_RPATH=		--force-rpath

# 32-bit NetBSD ports need libatomic
.  if ${MACHINE_PLATFORM:MNetBSD-*-powerpc} || \
      ${MACHINE_PLATFORM:MNetBSD-*-earmv[67]hf} || \
      ${MACHINE_PLATFORM:MNetBSD-*-mipsel} || \
      ${MACHINE_PLATFORM:MNetBSD-*-i386}
.    include "../../devel/libatomic/buildlink3.mk"
.  endif

.PHONY: fix-relative-rpath
post-install: fix-relative-rpath
fix-relative-rpath:
.  for bin in \
	bin/cargo \
	bin/cargo-clippy \
	bin/cargo-fmt \
	bin/clippy-driver \
	bin/miri  \
	bin/rls \
	bin/rust-analyzer \
	bin/rust-demangler \
	bin/rustc \
	bin/rustdoc \
	bin/rustfmt \
	libexec/rust-analyzer-proc-macro-srv
	if [ -f ${DESTDIR}${PREFIX}/${bin} ]; then \
		${PREFIX}/bin/patchelf ${FORCE_RPATH} --set-rpath \
		    ${PREFIX}/lib ${DESTDIR}${PREFIX}/${bin} ; \
	fi
.  endfor
# Only Linux builds link these binaries against an LLVM library
.  if ${OPSYS} == "Linux"
.    for bin in llc llvm-ar llvm-as llvm-cov llvm-dis llvm-link llvm-nm llvm-objcopy \
	   llvm-objdump llvm-profdata llvm-readobj llvm-size llvm-strip opt \
	   rust-lld gcc-ld/ld64.lld gcc-ld/ld.lld gcc-ld/lld-link gcc-ld/wasm-ld
	 ${PREFIX}/bin/patchelf ${FORCE_RPATH} --set-rpath ${RUST_LLVM_RPATH} \
	   ${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/${bin}
.    endfor
.  endif
.  for lib in lib lib/rustlib/${RUST_ARCH}/lib \
		lib/rustlib/${RUST_ARCH}/codegen-backends
	for f in ${DESTDIR}${PREFIX}/${lib}/lib*.so; do			\
		[ ! -f $$f ] && continue;				\
		${PREFIX}/bin/patchelf ${FORCE_RPATH} --set-rpath ${PREFIX}/lib $$f;	\
	done
.  endfor
# wrong architecture binary distributed, unused except on macOS
# https://github.com/rust-lang/rust/issues/139195
# https://github.com/rust-lang/rust/issues/138943
	${RM} -f ${DESTDIR}${PREFIX}/lib/rustlib/${RUST_ARCH}/bin/rust-objcopy
.endif

.include "../../mk/bsd.pkg.mk"
