# $NetBSD: Makefile,v 1.14 2010/01/18 09:38:25 thomasklausner Exp $
#

DISTNAME=		igowin
PKGNAME=		igowin-1.0
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		http://www.smart-games.com/
EXTRACT_SUFX=		.exe

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://www.smart-games.com/
COMMENT=		Go playing program

WRKSRC=			${WRKDIR}
EXTRACT_OPTS=		-f zip
NO_BUILD=		yes
USE_TOOLS+=		unzip

IGOWIN_FILES=		grain.bmp igowin.exe igowin.hlp readme.txt tutor.hlp
IGOWIN_DIR=		${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS=	bin share/${PKGBASE}

do-configure:
.for f in igowin.sh
	@${SED} -e 's|@SHELL@|${SHELL}|g'			\
		-e 's|@TEST@|${TEST}|g'				\
		-e 's|@MKDIR@|${MKDIR}|g'			\
		-e 's|@RM@|${RM}|g'				\
		-e 's|@LN@|${LN}|g'				\
		-e 's|@PKGDIR@|${IGOWIN_DIR}|g'			\
		-e 's|@FILES@|${IGOWIN_FILES}|g'		\
		${FILESDIR}/${f}.in > ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igowin.sh ${PREFIX}/bin/igowin
.for f in ${IGOWIN_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${IGOWIN_DIR}/${f}
.endfor

.include "../../emulators/wine/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
