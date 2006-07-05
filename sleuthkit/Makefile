# $NetBSD: Makefile,v 1.7 2006/07/05 16:40:57 thomasklausner Exp $
#

DISTNAME=		sleuthkit-2.04
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=sleuthkit/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://sleuthkit.sourceforge.net/
COMMENT=		OpenSource Forensic Toolkit

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl:run

SUBST_CLASSES+=		file
SUBST_MESSAGE.file=	Using external file(1) command.
SUBST_STAGE.file=	post-configure
SUBST_FILES.file=	src/sorter/sorter.base
SUBST_SED.file=		-e "s,..BIN_DIR.file,${BUILDLINK_PREFIX.file}/bin/file,"

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/sorter ${PREFIX}/bin/
	${RM} ${WRKSRC}/bin/sorter
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mactime ${PREFIX}/bin/
	${RM} ${WRKSRC}/bin/mactime
	${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/sorter/
	${INSTALL_DATA} ${WRKSRC}/share/sorter/* ${PREFIX}/share/sorter
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sleuthkit/
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/sleuthkit/

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
