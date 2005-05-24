# $NetBSD: Makefile,v 1.9 2005/05/24 18:43:08 rillig Exp $
#

DISTNAME=		igowin
PKGNAME=		igowin-1.0
CATEGORIES=		games
MASTER_SITES=		http://www.smart-games.com/
EXTRACT_SUFX=		.exe

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://www.smart-games.com/
COMMENT=		Go playing program

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${EXTRACT_CMD.zip}
NO_TOOLS=		yes
NO_BUILD=		yes
USE_TOOLS+=		unzip

IGOWIN_FILES=		grain.bmp igowin.exe igowin.hlp readme.txt tutor.hlp
IGOWIN_DIR=		${PREFIX}/libdata/${PKGNAME}

INSTALLATION_DIRS=	bin libdata/${PKGNAME}

do-configure:
.for _F_ in igowin.sh
	@${SED} -e 's|@SHELL@|${SHELL}|g'			\
		-e 's|@TEST@|${TEST}|g'				\
		-e 's|@MKDIR@|${MKDIR}|g'			\
		-e 's|@RM@|${RM}|g'				\
		-e 's|@LN@|${LN}|g'				\
		-e 's|@PKGDIR@|${IGOWIN_DIR}|g'			\
		-e 's|@FILES@|${IGOWIN_FILES}|g'		\
		${FILESDIR}/${_F_}.in > ${WRKSRC}/${_F_}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igowin.sh ${PREFIX}/bin/igowin
.for _F_ in ${IGOWIN_FILES}
	${INSTALL_DATA} ${WRKSRC}/${_F_} ${IGOWIN_DIR}/${_F_}
.endfor

.include "../../emulators/wine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
