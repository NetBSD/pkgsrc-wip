# $NetBSD: Makefile,v 1.1.1.1 2009/07/18 15:25:55 thomasklausner Exp $
#

DISTNAME=	ogsrc10
PKGNAME=	overgod-1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=overgod/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.allegro.cc/depot/Overgod
COMMENT=	Shoot'em Up
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin libexec share/doc/overgod
INSTALLATION_DIRS+=	share/overgod/gfx share/overgod/wavs/beat

do-build:
	cd ${WRKSRC} && \
		for i in *.c; \
		do \
			j=`${ECHO} $$i | sed "s/.c$$/.o/"`; \
			gcc  $$i `allegro-config --cflags` -o $$j -c; \
		done; \
		gcc -o overgod *.o `allegro-config --libs`
	${ECHO} "#!/bin/sh" > ${WRKSRC}/overgod.sh
	${ECHO} "cd ${PREFIX}/share/overgod && ${PREFIX}/libexec/overgod" \
		>> ${WRKSRC}/overgod.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/overgod ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/overgod.sh ${DESTDIR}${PREFIX}/bin/overgod
	${INSTALL_DATA} ${WRKSRC}/readme.txt \
		${DESTDIR}${PREFIX}/share/doc/overgod
	${INSTALL_DATA} ${WRKSRC}/gfx/* \
		${DESTDIR}${PREFIX}/share/overgod/gfx
	${INSTALL_DATA} ${WRKSRC}/wavs/*.* \
		${DESTDIR}${PREFIX}/share/overgod/wavs
	${INSTALL_DATA} ${WRKSRC}/wavs/beat/* \
		${DESTDIR}${PREFIX}/share/overgod/wavs/beat

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
