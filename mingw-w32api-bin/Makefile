# $NetBSD: Makefile,v 1.3 2003/11/30 23:56:27 mpasternak Exp $
# $Id: Makefile,v 1.3 2003/11/30 23:56:27 mpasternak Exp $

DISTNAME=		w32api-2.4
PKGNAME=		mingw-w32api-bin-2.4
WRKSRC=			${WRKDIR}
CATEGORIES=		cross

NO_BUILD=		yes
NO_CONFIGURE=		yes

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe include lib ${PREFIX}/${MINGWTARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
