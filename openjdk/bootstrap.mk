# $NetBSD: bootstrap.mk,v 1.5 2009/09/26 07:48:10 tnn2 Exp $

ONLY_FOR_PLATFORM=	NetBSD-5.*-i386 NetBSD-5.*-x86_64

BOOTKIT.i386=		bootstrap-jdk-7-bin-netbsd-5-i386-20090926.tar.bz2
SITES.${BOOTKIT.i386}=	http://mx1.nygren.pp.se/distfiles/
DISTFILES+=		${BOOTKIT.i386}

BOOTKIT.amd64=		bootstrap-jdk-7-bin-netbsd-5-amd64-20090925.tar.bz2
SITES.${BOOTKIT.amd64}=	http://mx1.nygren.pp.se/distfiles/
DISTFILES+=		${BOOTKIT.amd64}

.if !empty(MACHINE_PLATFORM:MNetBSD-5.*-i386)
EXTRACT_ONLY+=		${BOOTKIT.i386}
ALT_BOOTDIR=		${WRKDIR}/bootstrap
.endif

.if !empty(MACHINE_PLATFORM:MNetBSD-5.*-x86_64)
EXTRACT_ONLY+=		${BOOTKIT.amd64}
ALT_BOOTDIR=		${WRKDIR}/bootstrap
.endif

.if !exists(/usr/lib/libstdc++.so.6) || !exists(/usr/lib/libpthread.so.0)
PKG_FAIL_REASON+=	"Using NetBSD-current? If so, this package can build a native JDK for you."
PKG_FAIL_REASON+=	"But during the build, two compatibility libraries from NetBSD 5.0 must"
PKG_FAIL_REASON+=	"be available. Please fetch libstdc++.so.6 and libpthread.so.0 from the"
PKG_FAIL_REASON+=	"NetBSD 5.0 distribution and drop them in /usr/lib . After the package"
PKG_FAIL_REASON+=	"Has been built you can remove them."
.endif
