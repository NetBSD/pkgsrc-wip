# $NetBSD: Makefile,v 1.1 2004/06/25 15:09:20 rillig Exp $
#

DISTNAME=		cgoban-unix-2.6.1
PKGNAME=		cgoban2
CATEGORIES=		games
MASTER_SITES=		http://kgs.kiseido.com/

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://kgs.kiseido.com/
COMMENT=		Go client for the Kiseido Go Server

WRKSRC=			${WRKDIR}/cgoban
USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes
NO_TOOLS=		yes
NO_BUILDLINK=		yes

INSTALLATION_DIRS=	bin share/${PKGNAME}
CGOBAN2_ARCHIVE=	${PREFIX}/share/${PKGNAME}/cgoban.jar

do-build:
	{ \
	${ECHO} "#!/bin/sh" && \
	${ECHO} "exec java -jar ${CGOBAN2_ARCHIVE} \"\$$@\""; \
	} > ${WRKSRC}/cgoban2.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban2.sh ${PREFIX}/bin/cgoban2
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${CGOBAN2_ARCHIVE}

.include "../../mk/bsd.pkg.mk"
