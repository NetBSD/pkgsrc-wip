# $NetBSD: Makefile,v 1.2 2010/06/13 22:47:10 thomasklausner Exp $
#

DISTNAME=		libgksu1.2-1.3.7
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://people.debian.org/~kov/gksu/libgksu1.2/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.nongnu.org/gksu/
COMMENT=		Support library for gksu

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

SUBST_CLASSES+=   nodocs
SUBST_FILES.nodocs=  Makefile
SUBST_SED.nodocs  =  -e 's,docs,,g'
SUBST_STAGE.nodocs = post-configure

PKGCONFIG_OVERRIDE+=	libgksu/libgksu1.2.pc.in

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
