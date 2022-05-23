# $NetBSD$

PROGNAME=	mctcli
VERS=		0.0.2

DISTNAME=	${PROGNAME}-${VERS}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=0xDRRB/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://github.com/0xDRRB/mctcli/
COMMENT=	Simple tool for mapping and reading MIFARE Classic tags
LICENSE=	gnu-lgpl-v3


WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
USE_LANGUAGES+=	c

MAKE_ENV+=	OLDLIB="yes"
MAKE_ENV+=	SYSKEYFILE=${PREFIX}/share/mctcli/mctcli_keys.dic

INSTALLATION_DIRS=	bin share/mctcli

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGNAME} ${DESTDIR}/${PREFIX}/bin/${PROGNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/mctcli_keys.dic ${DESTDIR}/${PREFIX}/share/mctcli

.include "../../wip/libnfc/buildlink3.mk"
.include "../../wip/libfreefare/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
