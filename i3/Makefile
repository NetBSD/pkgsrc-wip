# $NetBSD: Makefile,v 1.1.1.1 2009/03/23 13:03:33 mstapelberg Exp $
#

PKGNAME=	i3-3a
DISTNAME=	i3-3.a
CATEGORIES=	x11
MASTER_SITES=	http://i3.zekjur.net/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael+pkgsrc@stapelberg.de
HOMEPAGE=	http://i3.zekjur.net/
COMMENT=	Improved dynamic tiling window manager

USE_TOOLS+=		gmake
BUILD_DEPENDS+=		asciidoc>=8.3.0:../../textproc/asciidoc
PKG_DESTDIR_SUPPORT=	user-destdir

CONF_FILES=${PREFIX}/share/doc/i3/i3.config ${PKG_SYSCONFDIR}/i3/config

post-build:
	cd ${WRKSRC} && gmake -C man

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/i3.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/xcb-util/buildlink3.mk"
.include "../../wip/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
