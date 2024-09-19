# $NetBSD$

PKGNAME=	openfodder-data-${GITHUB_RELEASE}
GITHUB_PROJECT=	data
DISTNAME=	Data.Pack.${GITHUB_RELEASE}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenFodder/}
GITHUB_RELEASE=	1.7.0
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenFodder/data/
COMMENT=	Data for the wip/openfodder
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/OpenFodder

do-build:
	${TRUE}

do-install:
	cd ${WRKDIR} && ${FIND} Campaigns -type d | while read d; do \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/OpenFodder/$$d" || exit 1; \
	done
	cd ${WRKDIR} && ${FIND} Campaigns -type f | while read f; do \
		${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/OpenFodder/$${f%/*}" || exit 1; \
	done
	cd ${WRKDIR} && ${FIND} Data -type d | while read d; do \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/OpenFodder/$$d" || exit 1; \
	done
	cd ${WRKDIR} && ${FIND} Data -type f | while read f; do \
		${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/OpenFodder/$${f%/*}" || exit 1; \
	done
	cd ${WRKDIR} && ${FIND} Saves -type d | while read d; do \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/OpenFodder/$$d" || exit 1; \
	done
	cd ${WRKDIR} && ${FIND} Saves -type f | while read f; do \
		${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/OpenFodder/$${f%/*}" || exit 1; \
	done
	cd ${WRKDIR} && ${FIND} Scripts -type d -and ! -path "Scripts/.*" | while read d; do \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/OpenFodder/$$d" || exit 1; \
	done
	cd ${WRKDIR} && ${FIND} Scripts -type f -and ! -path "Scripts/.*" | while read f; do \
		${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/OpenFodder/$${f%/*}" || exit 1; \
	done

.include "../../mk/bsd.pkg.mk"
