# $NetBSD$

PROGNAME=	mctcli
VERS=		0.0.3

DISTNAME=	${PROGNAME}-${VERS}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITLAB:=0xDRRB/}
#GITLAB_TAG=	v${PKGVERSION_NOREV}
GITLAB_TAG=	313e5399d51d4b79b44d988a1f3f36fd20b8b7fa

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://gitlab.com/0xDRRB/mctcli/
COMMENT=	Simple tool for mapping and reading MIFARE Classic tags
LICENSE=	gnu-lgpl-v3


WRKSRC=		${WRKDIR}/${PROGNAME}-${GITLAB_TAG}

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
