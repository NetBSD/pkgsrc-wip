# $NetBSD$

DISTNAME=	hw-probe-${PORTVERSION}
PORTVERSION=	1.6-beta
CATEGORIES=	sysutils perl5
GITHUB_PROJECT=	linuxhw
MASTER_SITES=	${MASTER_SITE_GITHUB:=hw-probe/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bsd-hardware.info
COMMENT=	Check operability of computer hardware and find drivers

LICENSE=	gnu-lgpl-v2.1 OR 4-clause-bsd

DEPENDS=	curl:../../www/curl \
		usbutil:../../sysutils/usbutil \
		mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts \
		smartmontools:../../sysutils/smartmontools

NO_BUILD=	yes

.include "<../../mk/bsd.prefs.mk>"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "aarch64")
DEPENDS+=	dmidecode:../../sysutils/dmidecode
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
DEPENDS+=	cpuid:../../sysutils/cpuid
.endif

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/hw-probe.pl ${DESTDIR}${PREFIX}/bin/hw-probe

.include "../../mk/bsd.pkg.mk"
