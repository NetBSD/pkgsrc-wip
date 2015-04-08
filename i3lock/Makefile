# $NetBSD: Makefile,v 1.6 2015/04/08 12:09:29 nros Exp $
#

DISTNAME=	i3lock-2.6
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3lock/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://i3wm.org/i3lock/
COMMENT=	Slightly improved screen locker based on slock
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

# print options before building...
MAKE_JOBS_SAFE=	no

MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR}
MAKE_ENV+=	NOLIBCAIRO=1

SPECIAL_PERMS+=	bin/i3lock ${SETUID_ROOT_PERMS}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3lock ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/i3lock.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
