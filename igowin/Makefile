# $NetBSD: Makefile,v 1.3 2004/06/27 15:56:45 rillig Exp $
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

EXTRACT_CMD=		${EXTRACT_CMD.zip}
IGOWIN_FILES=		grain.bmp igowin.exe igowin.hlp readme.txt tutor.hlp

INSTALLATION_DIRS=	bin share/${PKGNAME}

do-build:
.for FILE in igowin.sh
	@${SED} -e 's|@SHELL@|${SHELL}|g'			\
		-e 's|@TEST@|${TEST}|g'				\
		-e 's|@MKDIR@|${MKDIR}|g'			\
		-e 's|@RM@|${RM}|g'				\
		-e 's|@LN@|${LN}|g'				\
		-e 's|@PKGDIR@|${PREFIX}/share/${PKGNAME}|g'	\
		-e 's|@FILES@|${IGOWIN_FILES}|g'		\
		${FILESDIR}/${FILE}.in > ${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igowin.sh ${PREFIX}/bin/igowin
.for _F_ in ${IGOWIN_FILES}
	${INSTALL_DATA} ${WRKSRC}/${_F_} ${PREFIX}/share/${PKGNAME}/${_F_}
.endfor

.include "../../mk/bsd.pkg.mk"
