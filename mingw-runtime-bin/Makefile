# $NetBSD: Makefile,v 1.10 2008/05/26 13:59:45 tnn2 Exp $
# $Id: Makefile,v 1.10 2008/05/26 13:59:45 tnn2 Exp $

DISTNAME=	mingw-runtime-3.5
PKGNAME=	mingw-runtime-bin-3.5
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_MINGW}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mingw.sourceforge.net/
COMMENT=	GNU C Compiler for win32 cross development

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_CROSSBASE=	yes
USE_TOOLS+=	pax
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MINGW_TARGET}
	cd ${WRKSRC} && pax -rw -pe bin include lib ${PREFIX}/${MINGW_TARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
