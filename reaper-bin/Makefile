# $NetBSD: Makefile,v 1.2 2026/10/27 06:25:21 wiz Exp $

MAJOR=			7
MINOR=			85
DISTNAME=		reaper${MAJOR}${MINOR}_linux_${MACHINE_ARCH}
PKGNAME=		reaper-${MAJOR}.${MINOR}
CATEGORIES=		audio
MASTER_SITES=		https://www.reaper.fm/files/${MAJOR}.x/
DIST_SUBDIR=		reaper_linux_x86_64
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		ivan@ivanpollak.com
HOMEPAGE=		https://reaper.fm/
COMMENT=		Cross-platform digital audio workstation
LICENSE=		reaper-license

ONLY_FOR_PLATFORM=	Linux-*-x86_64
# ONLY_FOR_PLATFORM=	Darwin-*-aarch64

# Needed for the --integrate-user-desktop flag, which will create the .desktop
# file.
TOOL_DEPENDS+=		xdg-utils:../../misc/xdg-utils

WRKSRC=			${WRKDIR}/reaper_linux_${MACHINE_ARCH}
NO_BUILD=		yes

do-install:
	cd ${WRKSRC} \
	&& XDG_DATA_HOME=${DESTDIR}${PREFIX}/share \
		./install-reaper.sh \
		--install "${DESTDIR}${PREFIX}/lib" \
		--integrate-user-desktop

	rm -v "${DESTDIR}${PREFIX}/lib/REAPER/uninstall-reaper.sh"

	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${LN} -s "${DESTDIR}${PREFIX}/lib/REAPER/reaper" \
		"${DESTDIR}${PREFIX}/bin/reaper"

.include "../../mk/bsd.pkg.mk"
