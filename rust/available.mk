.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MDarwin-*-i386) || \
    !empty(MACHINE_PLATFORM:MDarwin-*-x86_64) || \
    !empty(MACHINE_PLATFORM:MLinux-*-i386) || \
    !empty(MACHINE_PLATFORM:MLinux-*-x86_64) || \
    !empty(MACHINE_PLATFORM:MSunOS-*-x86_64) || \
    !empty(MACHINE_PLATFORM:MNetBSD-*-x86_64)
RUST_AVAILABLE=		yes
.else
RUST_AVAILABLE=		no
.endif
