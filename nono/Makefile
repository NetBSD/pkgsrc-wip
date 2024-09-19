# $NetBSD$

DISTNAME=	nono-0.1.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.pastel-flower.jp/~isaki/nono/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pastel-flower.jp/~isaki/nono/archive/
COMMENT=	OMRON LUNA-I emulator that runs on NetBSD and so on
#LICENSE=	nono-license

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
MAKE_ENV+=		prefix=${PREFIX}


WRKSRC=			${WRKDIR}/nono-0.1.1

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wx/nono ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/cli/nono-cli ${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.prefs.mk"

.include "../../lang/clang/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
