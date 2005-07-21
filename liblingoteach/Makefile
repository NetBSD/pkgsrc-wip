# $NetBSD: Makefile,v 1.3 2005/07/21 16:34:05 thomasklausner Exp $
#

DISTNAME=		liblingoteach-0.2.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lingoteach/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://lingoteach.sourceforge.net/
COMMENT=		Library for lingoteach

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/liblingoteach.pc.in
GNU_CONFIGURE=		yes

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
