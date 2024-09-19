# $NetBSD: Makefile,v 1.10 2014/08/23 23:07:16 leot1990 Exp $
#

DISTNAME=	picprog-1.9.1
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://hyvatti.iki.fi/~jaakko/pic/picprog.html
COMMENT=	PIC16, PIC12 and PIC18 microcontroller programmer
LICENSE=	gnu-gpl-v3

NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	pre-build
SUBST_MESSAGE.makefile=	Fixing Makefile
SUBST_FILES.makefile=	Makefile
SUBST_SED.makefile+=	-e 's,/usr/local,${DESTDIR}${PREFIX},'
SUBST_SED.makefile+=	-e 's,man/man1,${PKGMANDIR}/man1,'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
