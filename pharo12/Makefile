# $NetBSD$

PHARO_VER=	12.0
PHARO_MAJOR=	${PHARO_VER:C/\..*//}
PHARO_PATCH=	0
PHARO_BUILD=	1585
PHARO_SHA=	83c728531a
PHARO_ARCH=	64bit

DISTNAME=	Pharo${PHARO_VER}-SNAPSHOT.build.${PHARO_BUILD}.sha.${PHARO_SHA}.arch.${PHARO_ARCH}
PKGNAME=	pharo${PHARO_MAJOR}-${PHARO_VER}.${PHARO_PATCH}.build${PHARO_BUILD}
CATEGORIES=	lang
MASTER_SITES=	http://files.pharo.org/image/${PHARO_VER:C/\.//}/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pharo.org/
COMMENT=	Pure object-oriented programming language and a powerful environment
LICENSE=	mit AND apache-2.0

DEPENDS+=	pharo-vm10-[0-9]*:../../wip/pharo-vm10

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_CONFIGURE=	yes
NO_BUILD=	yes

PHARO_DST=	share/pharo/${PHARO_VER}

INSTALLATION_DIRS=	${PHARO_DST}

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${PREFIX}/${PHARO_DST}

PHARO_SHA7=${PHARO_SHA:C/^(.{7}).*/\1/}

PRINT_PLIST_AWK+=	{gsub(/${PHARO_VER}/, "$${PHARO_VER}");}
PRINT_PLIST_AWK+=	{gsub(/${PHARO_ARCH}/, "$${PHARO_ARCH}");}
PRINT_PLIST_AWK+=	{gsub(/${PHARO_SHA}/, "$${PHARO_SHA}");}
PRINT_PLIST_AWK+=	{gsub(/${PHARO_SHA7}/, "$${PHARO_SHA7}");}

PLIST_SUBST+=	PHARO_VER=${PHARO_VER:Q}
PLIST_SUBST+=	PHARO_ARCH=${PHARO_ARCH:Q}
PLIST_SUBST+=	PHARO_SHA=${PHARO_SHA:Q}
PLIST_SUBST+=	PHARO_SHA7=${PHARO_SHA7:Q}

.include "../../mk/bsd.pkg.mk"
