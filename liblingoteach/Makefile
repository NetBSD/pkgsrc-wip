# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:47 tvierling Exp $
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

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
