# $NetBSD: Makefile,v 1.3 2003/12/02 02:03:04 mpasternak Exp $
# $Id: Makefile,v 1.3 2003/12/02 02:03:04 mpasternak Exp $

DISTNAME=		binutils-2.14.90-20030807-1-src
PKGNAME=		mingw-${DISTNAME:S/-20030807-1-src//}
CATEGORIES=		devel

post-install:
	${LN} -s ${PREFIX}/bin/${MINGWTARGET}-windres ${PREFIX}/${MINGWTARGET}/bin/windres

.include "../../wip/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
