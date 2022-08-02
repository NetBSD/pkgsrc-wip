# $NetBSD: options.mk,v 1.10 2018/01/04 20:31:28 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openmpi
PKG_SUPPORTED_OPTIONS=	debug f90 java
PKG_SUGGESTED_OPTIONS+=	f90

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

PLIST_VARS+=		f08 f90 java sge

.if !empty(PKG_OPTIONS:Mf90)
USE_LANGUAGES+=		fortran
GCC_REQD+=		4.7
CONFIGURE_ARGS+=	--enable-mpi-fortran=yes
# Enabling fortran builds for Fortran 90, and also for Fortran 08 if
# the toolchain is good enough.  In 2022, start by assuming that
# USE_LANGUAGES=fortran gets us a sufficiently modern compiler.
PLIST.f90=		yes
PLIST.f08=		yes
.else
CONFIGURE_ARGS+=	--enable-mpi-fortran=no
.endif

.if !empty(PKG_OPTIONS:Mjava)
CONFIGURE_ARGS+=	--enable-mpi-java
PLIST.java=		yes
.include "../../mk/java-vm.mk"
.else
CONFIGURE_ARGS+=	--disable-mpi-java
.endif

# \todo Keep sge, or add to COMMIT_MSG an explanation of why it is
# dropped.
CONFIGURE_ARGS+=	--without-sge
