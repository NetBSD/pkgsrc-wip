# $NetBSD: Makefile,v 1.5 2004/11/30 17:10:50 xtraeme Exp $
# $Id: Makefile,v 1.5 2004/11/30 17:10:50 xtraeme Exp $

DISTNAME=	mingw-runtime-3.5
PKGNAME=	mingw-runtime-bin-3.5
WRKSRC=		${WRKDIR}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_MINGW}

MAINTAINER=	dotz@irc.pl
HOMEPAGE=	http://mingw.sf.net/
COMMENT=	GNU C Compiler for win32 cross development

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_CROSSBASE=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MINGW_TARGET}
	cd ${WRKSRC} && ${PAX} -rw -pe bin include lib ${PREFIX}/${MINGW_TARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
