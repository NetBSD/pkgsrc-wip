# $NetBSD: Makefile,v 1.2 2003/11/29 20:03:09 mpasternak Exp $
# $Id: Makefile,v 1.2 2003/11/29 20:03:09 mpasternak Exp $

DISTNAME=		w32api-2.4
PKGNAME=		mingw-w32api-bin-2.4
WRKSRC=			${WRKDIR}
CATEGORIES=		cross

NO_BUILD=		yes
NO_CONFIGURE=		yes

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe include lib ${PREFIX}/${MINGWTARGET}

.include "../../wip/mingw/Makefile.common"
