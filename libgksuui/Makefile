# $NetBSD: Makefile,v 1.3 2010/06/13 22:47:10 thomasklausner Exp $
#

DISTNAME=		libgksuui1.0-1.0.7
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://people.debian.org/~kov/gksu/old_stuff/libgksuui1.0/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://people.debian.org/~kov/gksu/
COMMENT=		UI Support library for Gksu

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config gmake
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libgksuui/libgksuui1.0.pc.in

SUBST_CLASSES+=	nodocs
SUBST_FILES.nodocs=	Makefile
SUBST_SED.nodocs  =  -e 's,docs,,g'
SUBST_STAGE.nodocs = post-configure

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
