# $NetBSD: Makefile,v 1.2 2007/03/01 19:12:15 shattered Exp $
#

DISTNAME=		confuse-2.5
CATEGORIES=		devel
MASTER_SITES=		http://download.savannah.gnu.org/releases/confuse/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://download.savannah.gnu.org/releases/confuse/
COMMENT=		A library to parse configuration files

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libconfuse.pc.in

.include "../../mk/bsd.pkg.mk"
