# $NetBSD: Makefile,v 1.2 2011/02/12 10:52:53 ryo-on Exp $
#

DISTNAME=	nodau-0.2.1
CATEGORIES=	editors
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://sandbox.ltmnet.com/nodau
COMMENT=	Nodau is a simple console based note taking program
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin \
			${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}/nodau
USE_LANGUAGES=	c
USE_TOOLS+=	gmake

BUILD_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	BIN_DIR=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"
.if !empty(OPSYS:M*BSD) || !empty(OPSYS:MDragonFly)
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
