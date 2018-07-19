# $NetBSD$

PKGNAME=	vmware-sercons-0
CATEGORIES=	comms
GHCOMMIT=	216095b5d16748e63223b44c0f12bbb0d16a6e66
DISTNAME=	${GHCOMMIT}
MASTER_SITES=	${MASTER_SITE_GITHUB:=jclulow/vmware-sercons/archive/}
DIST_SUBDIR=	vmware-sercons
WRKSRC=		${WRKDIR}/vmware-sercons-${GHCOMMIT}

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://github.com/jclulow/vmware-sercons
COMMENT=	Tool for attaching simply to VMware Fusion Serial Consoles
LICENSE=	mit

NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin
USE_TOOLS+=		gmake
BUILD_TARGET=		sercons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sercons ${DESTDIR}${PREFIX}/bin

.include	"../../mk/bsd.pkg.mk"
