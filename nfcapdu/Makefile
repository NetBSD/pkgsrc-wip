# $NetBSD$

PROGNAME=	nfcapdu
VERS=		0.0.1

DISTNAME=	${PROGNAME}-${VERS}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=0xDRRB/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	lefinnois@lefinnois.net
HOMEPAGE=	https://github.com/0xDRRB/nfcapdu/
COMMENT=	Command line tool to exchange APDUs with an RFID/NFC tag
LICENSE=	gnu-lgpl-v3


WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES+=	c

EGDIR=		${PREFIX}/share/examples/nfcapdu

INSTALLATION_DIRS=	bin ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PROGNAME} ${DESTDIR}/${PREFIX}/bin/${PROGNAME}

post-install:
	${INSTALL_DATA} ${WRKSRC}/nfcapdurc_sample ${DESTDIR}${EGDIR}/nfcapdurc

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/libnfc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
