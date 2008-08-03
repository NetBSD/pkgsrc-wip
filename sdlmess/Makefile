# $NetBSD: Makefile,v 1.3 2008/08/03 15:34:34 dillo Exp $
#

DISTNAME=		sdlmess0126
PKGNAME=		sdlmess-0.126

COMMENT=		Multi Emulator Super System, SDL port

CONFLICTS=		xmess-[0-9]*

MAKE_FILE=		makefile.sdl

DOCDIR=			share/doc/mess
SHAREDIR=		share/mess
INSTALLATION_DIRS=	bin ${DOCDIR}/sysinfo ${SHAREDIR}/artwork \
			${SHAREDIR}/hash

post-build:
	cd ${WRKSRC} && ./dat2html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imgtool ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mess ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/artwork/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/artwork
	${INSTALL_DATA} ${WRKSRC}/hash/* \
		${DESTDIR}${PREFIX}/${SHAREDIR}/hash
	${INSTALL_DATA} ${WRKSRC}/sysinfo.htm ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/sysinfo/* \
		${DESTDIR}${PREFIX}/${DOCDIR}/sysinfo

.include "../../wip/sdlmame/Makefile.common"
