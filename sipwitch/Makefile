# $NetBSD: Makefile,v 1.7 2013/08/21 11:44:14 thomasklausner Exp $
#

DISTNAME=	sipwitch-1.6.1
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

.include "options.mk"

SUBST_CLASSES+=		files
SUBST_STAGE.files=	post-configure
SUBST_MESSAGE.files=	Fixing paths and permissions.
SUBST_FILES.files=	cmake_install.cmake server/cmake_install.cmake
SUBST_SED.files=	-e 's,lib64,lib,g'
SUBST_SED.files+=	-e 's|SETUID|SETUID OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE|1'

SPECIAL_PERMS+=		bin/sippasswd ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 4555

.include "../../net/libexosip/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.ucommon+=	ucommon>=6.0.0
.include "../../devel/ucommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
