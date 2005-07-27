# $NetBSD: Makefile,v 1.6 2005/07/27 16:26:14 thomasklausner Exp $
#

DISTNAME=		libtlen2-20040301
CATEGORIES=		chat
MASTER_SITES=		http://www.libtlen.eu.org/libtlen2_files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.libtlen.eu.org/index.php?theme=teary&page=libtlen2
COMMENT=		Library to access tlen.pl IM system

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libtlen-2.0.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
