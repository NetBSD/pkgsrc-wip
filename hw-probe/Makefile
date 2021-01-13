# $NetBSD$

DISTNAME=	hw-probe
PKGNAME=	hw-probe-1.6beta
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://bsd-hardware.info/
EXTRACT_SUFX=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bsd-hardware.info/
COMMENT=	Check operability of computer hardware and find drivers
LICENSE=	gnu-lgpl-v2.1 OR original-bsd

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	usbutil-[0-9]*:../../sysutils/usbutil
DEPENDS+=	mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
DEPENDS+=	smartmontools-[0-9]*:../../sysutils/smartmontools

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=		${WRKDIR}

REPLACE_PERL+=	hw-probe

USE_TOOLS+=	perl:run

INSTALLATION_DIRS+=	bin

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64") || (${MACHINE_ARCH} == "aarch64")
DEPENDS+=	dmidecode-[0-9]*:../../sysutils/dmidecode
.endif

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "x86_64")
DEPENDS+=	cpuid-[0-9]*:../../sysutils/cpuid
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/hw-probe ${DESTDIR}${PREFIX}/bin/hw-probe

.include "../../mk/bsd.pkg.mk"
