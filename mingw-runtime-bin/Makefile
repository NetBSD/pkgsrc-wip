# $NetBSD: Makefile,v 1.4 2004/06/20 05:05:24 xtraeme Exp $
# $Id: Makefile,v 1.4 2004/06/20 05:05:24 xtraeme Exp $

DISTNAME=		mingw-runtime-3.3
PKGNAME=		mingw-runtime-bin-3.3
WRKSRC=			${WRKDIR}
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://mingw.sf.net/
COMMENT=		GNU C Compiler for win32 cross development

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_CROSSBASE=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${MINGW_TARGET}
	cd ${WRKSRC} && ${PAX} -rw -pe bin include lib ${PREFIX}/${MINGW_TARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
