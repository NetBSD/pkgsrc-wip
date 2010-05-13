# $NetBSD: Makefile,v 1.2 2010/05/13 08:25:51 jihbed Exp $
#

DISTNAME=	yauap-0.2.4
CATEGORIES=	audio
MASTER_SITES=	http://mirrors.linhub.com/savannah/yauap/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/yauap/index.html
COMMENT=	Yauap is a simple commandline audio player
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=  c c++


INSTALLATION_DIRS= 	bin share/doc

do-build:
	cd ${WRKSRC} && ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/yauap \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/yauap

.include "../../devel/glib2/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-good/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
