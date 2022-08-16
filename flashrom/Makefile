# $NetBSD$

PROGNAME=	flashrom
VERS=		1.2

DISTNAME=	${PROGNAME}-${VERS}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=flashrom/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://www.flashrom.org/Flashrom
COMMENT=	Utility to identify, read, write, verify and erase flash chips
LICENSE=	gnu-gpl-v2


WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGNAME} ${DESTDIR}/${PREFIX}/bin/${PROGNAME}
	${INSTALL_MAN} ${WRKSRC}/${PROGNAME}.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/libftdi1/buildlink3.mk"
.include "../../sysutils/pciutils/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
