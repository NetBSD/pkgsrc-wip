# $NetBSD: Makefile,v 1.13 2008/07/26 13:25:33 obache Exp $

DISTNAME=		w32api-3.11
PKGNAME=		mingw-w32api-bin-3.11
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mingw.sourceforge.net/
COMMENT=		GNU C Compiler for win32 cross development

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS+=	${MINGW_TARGET}

do-install:
	cd ${WRKSRC} && pax -rw -pe include lib \
		${DESTDIR}${PREFIX}/${MINGW_TARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
