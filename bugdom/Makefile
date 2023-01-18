# $NetBSD$

DISTNAME=	bugdom-1.3.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jorio/}
DISTFILES+=	${DEFAULT_DISTFILES} ${POMME}

POMME=		88a3e4625b00f63cde90aae5ce383d85c83cc5a8.tar.gz
SITES.${POMME}=	${MASTER_SITE_GITHUB:=jorio/}Pomme/archive/

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://pangeasoft.net/bug/
COMMENT=	Pangea Software's Bugdom for modern systems
LICENSE=	cc-by-nc-sa-v4.0-license

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pax pkg-config

WRKSRC=		${WRKDIR}/Bugdom-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/bugdom/Data

post-extract:
	${RM} -rf ${WRKSRC}/extern/Pomme
	${LN} -sf ${WRKDIR}/Pomme-${POMME:S/.tar.gz//} ${WRKSRC}/extern/Pomme

pre-configure:
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' \
		${FILESDIR}/bugdom.template > ${WRKDIR}/bugdom

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/bugdom ${DESTDIR}${PREFIX}/bin/bugdom
	${INSTALL_PROGRAM} ${WRKSRC}/Bugdom ${DESTDIR}${PREFIX}/libexec
	(cd ${WRKSRC}/Data && ${PAX} -r -w . ${DESTDIR}${PREFIX}/share/bugdom/Data)

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
