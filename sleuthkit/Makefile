# $NetBSD: Makefile,v 1.9 2012/10/07 15:22:10 asau Exp $
#

DISTNAME=		sleuthkit-2.04
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.sleuthkit.org/
COMMENT=		OpenSource Forensic Toolkit

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl:run

SUBST_CLASSES+=		file
SUBST_MESSAGE.file=	Using external file(1) command.
SUBST_STAGE.file=	post-configure
SUBST_FILES.file=	src/sorter/sorter.base
SUBST_SED.file=		-e "s,..BIN_DIR.file,${BUILDLINK_PREFIX.file}/bin/file,"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sorter ${DESTDIR}${PREFIX}/bin/
	${RM} ${WRKSRC}/bin/sorter
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mactime ${DESTDIR}${PREFIX}/bin/
	${RM} ${WRKSRC}/bin/mactime
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/sorter/
	${INSTALL_DATA} ${WRKSRC}/share/sorter/* ${DESTDIR}${PREFIX}/share/sorter
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/sleuthkit/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/sleuthkit/

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
