# $NetBSD: Makefile,v 1.1.1.1 2006/03/12 22:09:56 poppnk Exp $
#

DISTNAME=		confuse-2.5
CATEGORIES=		wip devel
MASTER_SITES=		http://download.savannah.gnu.org/releases/confuse/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://download.savannah.gnu.org/releases/confuse/
COMMENT=		A library to parse configuration files

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libconfuse.pc.in

.include "../../mk/bsd.pkg.mk"
