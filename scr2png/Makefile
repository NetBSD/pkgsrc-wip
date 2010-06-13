# $NetBSD: Makefile,v 1.4 2010/06/13 22:47:15 thomasklausner Exp $

DISTNAME=		scr2png-1.1
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_FREEBSD_LOCAL:=nik/}

# the cp850-8x16.fnt was retrieved from FreeBSD

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE=
COMMENT=		Converts the output of FreeBSD "vidcontrol -p" to PNG

WRKSRC=			${WRKDIR}
CFLAGS+=		-DPREFIX=\"${PREFIX}\"
LDFLAGS+=		${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gd}/lib
LDFLAGS+=		-L${LOCALBASE}/lib
MAKE_ENV+=		MKMAN=no
PKGMANDIR?=		man

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/scr2png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scr2png ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/scr2png.1 ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA}	${FILESDIR}/cp850-8x16.fnt ${PREFIX}/share/scr2png/

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
