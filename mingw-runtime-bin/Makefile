# $NetBSD: Makefile,v 1.7 2005/07/27 16:26:39 thomasklausner Exp $
# $Id: Makefile,v 1.7 2005/07/27 16:26:39 thomasklausner Exp $

DISTNAME=	mingw-runtime-3.5
PKGNAME=	mingw-runtime-bin-3.5
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_MINGW}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mingw.sf.net/
COMMENT=	GNU C Compiler for win32 cross development

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_CROSSBASE=	yes
WRKSRC=		${WRKDIR}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MINGW_TARGET}
	cd ${WRKSRC} && ${PAX} -rw -pe bin include lib ${PREFIX}/${MINGW_TARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
