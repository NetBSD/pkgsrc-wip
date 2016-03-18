# $NetBSD: Makefile,v 1.7 2015/04/08 14:38:42 nros Exp $
#

DISTNAME=	i3lock-2.7
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3lock/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pallegra@gmail.com
HOMEPAGE=	http://i3wm.org/i3lock/
COMMENT=	Slightly improved screen locker based on slock
LICENSE=	modified-bsd

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	SYSCONFDIR=${PKG_SYSCONFDIR}

INSTALLATION_DIRS=	${PKGMANDIR}/man1 share/doc/${PKGBASE} ${EGDIR}
CONF_FILES+=		${EGDIR}/pam.d/i3lock /etc/pam.d/i3lock

EGDIR=	${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_MAN} ${WRKSRC}/i3lock.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/pam.d ${DESTDIR}${EGDIR}

.include "../../devel/libev/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
