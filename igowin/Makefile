# $NetBSD: Makefile,v 1.1 2004/06/25 16:59:42 rillig Exp $
#

DISTNAME=		igowin
PKG_VERSION=		1.0
CATEGORIES=		games
MASTER_SITES=		http://www.smart-games.com/
EXTRACT_SUFX=		.exe

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://www.smart-games.com/
COMMENT=		Go playing program

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
NO_BUILDLINK=		yes
NO_TOOLS=		yes
NO_BUILD=		yes

EXTRACT_CMD=		${EXTRACT_CMD.zip}
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
DEPENDS+=		wine-[0-9]*:../../emulators/wine

INSTALLATION_DIRS=	bin share/${PKGNAME}

# igowin creates a "learning" file in its current directory. It also
# expects its data files there. So we build a symlink directory and
# run the program therein.
do-configure:
	{ \
	${ECHO} "#!/bin/sh" && \
	${ECHO} "set -e" && \
	${ECHO} "workdir=\"$$HOME/.igowin\"" && \
	${ECHO} "if ${TEST} ! -d \"\$$workdir\"; then" && \
	${ECHO} "  ${MKDIR} \"\$$workdir\"" && \
	${ECHO} "  ${LN} -s ${PREFIX}/share/${PKGNAME}/* \"\$$workdir\"" && \
	${ECHO} "fi" && \
	${ECHO} "cd \"\$$workdir\"" && \
	${ECHO} "exec wine ./igowin.exe \"\$$@\""; \
	} > ${WRKSRC}/igowin.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igowin.sh ${PREFIX}/bin/igowin
.for _F_ in grain.bmp igowin.exe igowin.hlp readme.txt tutor.hlp
	${INSTALL_DATA} ${WRKSRC}/${_F_} ${PREFIX}/share/${PKGNAME}/${_F_}
.endfor

.include "../../mk/bsd.pkg.mk"
