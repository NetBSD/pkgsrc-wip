# $NetBSD: Makefile,v 1.2 2004/06/25 17:07:32 thomasklausner Exp $
#

DISTNAME=		igowin
PKGNAME=		igowin-1.0
CATEGORIES=		games
MASTER_SITES=		http://www.smart-games.com/
EXTRACT_SUFX=		.exe

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://www.smart-games.com/
COMMENT=		Go playing program

BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
DEPENDS+=		wine-[0-9]*:../../emulators/wine

WRKSRC=			${WRKDIR}
NO_BUILDLINK=		yes
NO_TOOLS=		yes
NO_BUILD=		yes

EXTRACT_CMD=		${EXTRACT_CMD.zip}

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
