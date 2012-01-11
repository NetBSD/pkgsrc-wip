# $NetBSD: Makefile,v 1.1.1.1 2012/01/11 23:30:24 othyro Exp $
#

DISTNAME=	sipwitch-1.2.0
CATEGORIES=	net
MASTER_SITES=	http://ftp.gnu.org/gnu/sipwitch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/sipwitch/
COMMENT=	Secure peer-to-peer VoIP server that uses the SIP protocol
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libsipwitch.pc.in

.include "options.mk"

.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../net/avahi/buildlink3.mk"
.include "../../wip/ucommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
