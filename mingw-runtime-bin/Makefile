# $NetBSD: Makefile,v 1.2 2003/11/30 23:56:27 mpasternak Exp $
# $Id: Makefile,v 1.2 2003/11/30 23:56:27 mpasternak Exp $

DISTNAME=		mingw-runtime-3.2
PKGNAME=		mingw-runtime-bin-3.2
WRKSRC=			${WRKDIR}
CATEGORIES=		cross

NO_BUILD=		yes
NO_CONFIGURE=		yes

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pe bin include lib ${PREFIX}/${MINGWTARGET}

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
