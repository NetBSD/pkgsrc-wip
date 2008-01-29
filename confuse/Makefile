# $NetBSD: Makefile,v 1.6 2008/01/29 02:28:06 hoka_adam Exp $
#

DISTNAME=	confuse-2.6
CATEGORIES=	devel
MASTER_SITES=	http://bzero.se/confuse/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://download.savannah.gnu.org/releases/confuse/
COMMENT=	Configuration file parser library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libconfuse.pc.in
INSTALLATION_DIRS=	lib include

.include "../../mk/bsd.pkg.mk"
