# $NetBSD: Makefile,v 1.6 2012/10/03 09:10:39 asau Exp $
#

DISTNAME=		liblingoteach-0.2.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lingoteach/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lingoteach.sourceforge.net/
COMMENT=		Library for lingoteach


USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/liblingoteach.pc.in
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
