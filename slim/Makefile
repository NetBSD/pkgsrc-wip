# $NetBSD: Makefile,v 1.1.1.1 2003/11/27 18:12:42 marc Exp $
#

DISTNAME=		slim-0.2.0
CATEGORIES=		devel
MASTER_SITES=		http://cairographics.org/snapshots/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://cairographics.org/
COMMENT=		Shared Library Interface Macros

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/slim.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
