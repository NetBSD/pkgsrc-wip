# $NetBSD$

PKGNAME=		${DISTNAME:S/-/i-/}

PATCHDIR=		../../wip/vnstat/patches
PKGDIR=			../../wip/vnstat
PLIST_SRC=		PLIST
DESCR_SRC=		../../wip/vnstat/DESCR DESCR

CONFLICTS+=		vnstat<2.13

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vnstati \
	  ${DESTDIR}${PREFIX}/bin/vnstati
	${INSTALL_MAN} ${WRKSRC}/man/vnstati.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/vnstati.1

.include "../../wip/vnstat/Makefile.common"
.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
