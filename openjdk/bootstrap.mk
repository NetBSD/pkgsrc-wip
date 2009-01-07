# $NetBSD: bootstrap.mk,v 1.1.1.1 2009/01/07 12:33:56 tnn2 Exp $

ONLY_FOR_PLATFORM=	NetBSD-5.*-i386 NetBSD-5.*-x86_64

BOOTKIT.i386=		bootstrap-jdk-7-bin-netbsd-5-i386-20090107.tar.bz2
SITES.${BOOTKIT.i386}=	http://mx1.nygren.pp.se/distfiles/
DISTFILES+=		${BOOTKIT.i386}

BOOTKIT.amd64=		bootstrap-jdk-7-bin-netbsd-5-amd64-20090106.tar.bz2
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

.if defined(PKG_DEVELOPER)
bootstrapkit:
	mkdir ${WRKSRC}/bootstrap
	cd ${BUILDDIR}/j2sdk-image && pax -rwpp $$(cat ${FILESDIR}/PLIST.boot | sed 's/$${ARCH}/amd64/') ${WRKSRC}/bootstrap
	cd ${WRKSRC} && tar cjvf bootstrap.tar.bz2 bootstrap
.endif
