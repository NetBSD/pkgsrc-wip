# $NetBSD: Makefile,v 1.11 2008/05/26 13:59:45 tnn2 Exp $

DISTNAME=		w32api-3.1
PKGNAME=		mingw-w32api-bin-3.1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mingw.sourceforge.net/
COMMENT=		GNU C Compiler for win32 cross development

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MINGW_TARGET}
	cd ${WRKSRC} && pax -rw -pe include lib ${PREFIX}/${MINGW_TARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
