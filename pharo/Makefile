# $NetBSD$

PHARO_BUILD=	1574
PHARO_SHA=	6f28d0a
PHARO_ARCH=	64bit

DISTNAME=	Pharo9.0-SNAPSHOT.build.${PHARO_BUILD}.sha.${PHARO_SHA}.arch.${PHARO_ARCH}
PKGNAME=	pharo-9.0.0.${PHARO_BUILD}
CATEGORIES=	lang
MASTER_SITES=	http://files.pharo.org/image/90/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pharo.org/
COMMENT=	Pure object-oriented programming language and a powerful environment
LICENSE=	mit AND apache-2.0

DEPENDS+=	pharo-vm-[0-9]*:../../wip/pharo-vm

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS=	share/pharo

PHARO_SRC=	${WRKSRC}/Pharo9.0-SNAPSHOT-${PHARO_ARCH}-${PHARO_SHA}
PHARO_DST=	${DESTDIR}${PREFIX}/share/pharo/

do-install:
	${INSTALL_DATA} ${PHARO_SRC}.image   ${PHARO_DST}/Pharo.image
	${INSTALL_DATA} ${PHARO_SRC}.changes ${PHARO_DST}/Pharo.changes
	${INSTALL_DATA} ${PHARO_SRC:C/SNAPSHOT-//}.sources ${PHARO_DST}

PRINT_PLIST_AWK+=	{gsub(/${PHARO_ARCH}/, "$${PHARO_ARCH}");}
PRINT_PLIST_AWK+=	{gsub(/${PHARO_SHA}/, "$${PHARO_SHA}");}

PLIST_SUBST+=	PHARO_ARCH=${PHARO_ARCH:Q}
PLIST_SUBST+=	PHARO_SHA=${PHARO_SHA:Q}

.include "../../mk/bsd.pkg.mk"
