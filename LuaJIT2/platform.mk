# $NetBSD$

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(PLATFORM_SUPPORTS_LUAJIT)

.  for luajit_arch in *arm* i386 mipseb mipsel powerpc x86_64
LUAJIT_PLATFORMS+=		*-*-${luajit_arch}
.  endfor

.  for luajit_platform in ${LUAJIT_PLATFORMS}
.    if !empty(MACHINE_PLATFORM:M${luajit_platform})
PLATFORM_SUPPORTS_LUAJIT=	yes
.    endif
.  endfor
PLATFORM_SUPPORTS_LUAJIT?=	no

.endif	# !defined(PLATFORM_SUPPORTS_LUAJIT)
