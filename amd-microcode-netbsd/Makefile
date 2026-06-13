# $NetBSD: $

DISTNAME=	amd-microcode-netbsd-20260416
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=kernel-firmware/}
GITLAB_PROJECT=	linux-firmware
GITLAB_TAG=	8c0d4738ee35318b8d51d8486663d7e7ae93a989

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://gitlab.com/kernel-firmware/linux-firmware
COMMENT=	Firmware updates for AMD processors
LICENSE=	amd-microcode-license

# Use of this package relies on NetBSD's cpuctl(8).
ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=		${WRKDIR}/linux-firmware-${GITLAB_TAG}/amd-ucode

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} < 069900
PKG_SKIP_REASON+=	"Loading microcode not supported"
.endif

INSTALLATION_DIRS+=	libdata/firmware/amd-ucode
INSTALLATION_DIRS+=	share/doc/amd-microcode-netbsd

RCD_SCRIPTS+=	amd-microcode

do-configure:

do-build:

do-install:
	${INSTALL_DATA} ${FILESDIR}/README \
		${DESTDIR}${PREFIX}/share/doc/amd-microcode-netbsd
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/libdata/firmware/amd-ucode
	${FIND} ${WRKSRC} -type f -name "*.bin" -exec ${INSTALL_DATA} {} \
		${DESTDIR}${PREFIX}/libdata/firmware/amd-ucode \;


.include "../../mk/bsd.pkg.mk"
