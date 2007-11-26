# $NetBSD: Makefile,v 1.4 2007/11/26 15:40:58 hoka_adam Exp $
#

DISTNAME=		confuse-2.5
PKGREVISION=	1
CATEGORIES=		devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/confuse/

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://download.savannah.gnu.org/releases/confuse/
COMMENT=	Configuration file parser library

GNU_CONFIGURE=		yes
USE_TOOLS+=			pkg-config
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	libconfuse.pc.in
INSTALLATION_DIRS=		lib include

.include "../../mk/bsd.pkg.mk"
