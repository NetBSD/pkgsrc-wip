# $NetBSD: Makefile,v 1.3 2012/10/07 17:17:52 asau Exp $
#

DISTNAME=	tw_cli-${EMUL_OPSYS}-${DIST_ARCH}-9.5.0.1
PKGNAME=	tw_cli-9.5.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.3ware.com/download/Escalade9690SA-Series/9.5.0.1/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.3ware.com/support/
COMMENT=	AMCC/3ware Strage Controller Management Command Line Interface
LICENSE=	3ware-license

LICENSE_FILE=	LICENSE
RESTRICTED=	Redistribution is not permitted
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_BUILD=		yes

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

INSTALL_UNSTRIPPED=	yes

EMUL_PLATFORMS=	freebsd-i386 freebsd-x86_64
EMUL_PLATFORMS+=linux-i386 linux-x86_64

.include "../../mk/bsd.prefs.mk"

DIST_ARCH.i386=		x86
DIST_ARCH.x86_64=	x86_64
DIST_ARCH=		${DIST_ARCH.${EMUL_ARCH}}

# On NetBSD, Linux version is useless.
.if ${OPSYS} == "NetBSD"
EMUL_PLATFORM=		freebsd-${MACHINE_ARCH}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tw_cli ${DESTDIR}${PREFIX}/sbin/tw_cli
	${INSTALL_MAN} ${WRKDIR}/tw_cli.8.nroff ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/tw_cli.8

.include "../../mk/bsd.pkg.mk"
