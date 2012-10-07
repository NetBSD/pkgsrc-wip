# $NetBSD: Makefile,v 1.3 2012/10/07 16:23:07 asau Exp $
#

DISTNAME=	sipwitch-1.2.4
CATEGORIES=	net
MASTER_SITES=	http://ftp.gnu.org/gnu/sipwitch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sipwitch/
COMMENT=	Secure peer-to-peer VoIP server that uses the SIP protocol
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libsipwitch.pc.in

PLIST_VARS=		qt

.include "options.mk"

SUBST_CLASSES+=		libdir
SUBST_STAGE.libdir=	post-configure
SUBST_MESSAGE.libdir=	Fixing libdir path.
SUBST_FILES.libdir=	cmake_install.cmake
SUBST_SED.libdir=	-e 's,lib64,lib,g'

.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../wip/ucommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
