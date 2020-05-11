# $NetBSD: Makefile,v 0.2 2018/09/06 16:15:10 andyb Exp $

DISTNAME=	enlightenment-0.23.1
CATEGORIES=	wm
MASTER_SITES=	https://download.enlightenment.org/rel/apps/enlightenment/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://www.enlightenment.org/
COMMENT=	The Enlightenment window manager
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	src/modules/everything/everything.pc.in

MESON_ARGS+=	-Dsystemd=false
MESON_ARGS+=	-Ddevice-udev=false

#EGDIR=			${PREFIX}/share/examples/enlightenment0224
#INSTALLATION_DIRS=	share/doc/enlightenment0224

#pre-install:
#	${INSTALL_DATA} ${WRKSRC}/data/etc/enlightenment.menu ${DESTDIR}${EGDIR}
#	${INSTALL_DATA} ${WRKSRC}/data/etc/sysactions.conf ${DESTDIR}${EGDIR}

.include "../../devel/meson/build.mk"
.include "../../wip/efl-current/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
