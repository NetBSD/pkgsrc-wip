# $NetBSD: platform.mk,v 1.27 2024/08/01 15:24:39 tnn Exp $

# This file encodes whether a given platform has support for rust.

# Platforms where rust ought to work but does not require a link to an
# open PR.

.if !defined(PLATFORM_SUPPORTS_RUST)

# Rust needs NetBSD>8
.for rust_arch in aarch64 earmv6hf earmv7hf i386 powerpc riscv64 sparc64 x86_64
.  for rust_os in Darwin FreeBSD Linux NetBSD SunOS
.    if ${OPSYS} != "NetBSD" || empty(OS_VERSION:M[0-8].*)
RUST_PLATFORMS+=	${rust_os}-*-${rust_arch}
.    endif
.  endfor
.endfor

RUST_DIR?=	../../lang/rust

.for rust_platform in ${RUST_PLATFORMS}
.  if !empty(MACHINE_PLATFORM:M${rust_platform})
PLATFORM_SUPPORTS_RUST=		yes
.  endif
.endfor
PLATFORM_SUPPORTS_RUST?=	no

.endif # !defined(PLATFORM_SUPPORTS_RUST)
