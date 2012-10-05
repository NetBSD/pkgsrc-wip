# $NetBSD: Makefile,v 1.7 2012/10/05 11:31:52 asau Exp $
#

DISTNAME=		pmars-0_8_6_tar
PKGNAME=		pmars-0.8.6
CATEGORIES=		games
MASTER_SITES=		http://www.koth.org/pmars/
EXTRACT_SUFX=		.gz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.koth.org/pmars/
COMMENT=		The official Core Wars simulator

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		pkg-config gmake
MAKE_FILE=		makefile

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD" && ${OPSYS} != "FreeBSD" && ${OPSYS} != "SunOS"
BUILD_DEPENDS+=		ex-[0-9]*:../../editors/ex
.endif

INSTALLATION_DIRS+=	bin share/pmars share/pmars/warriors ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pmars ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/pmars/
	${INSTALL_DATA} ${WRKSRC}/CONTRIB ${DESTDIR}${PREFIX}/share/pmars/
	${INSTALL_DATA} ${WRKSRC}/*.red ${DESTDIR}${PREFIX}/share/pmars/warriors/
	${INSTALL_MAN} ${WRKSRC}/pmars.6 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man6

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
