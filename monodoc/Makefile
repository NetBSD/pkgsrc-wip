# $NetBSD: Makefile,v 1.1.1.1 2004/04/05 14:38:27 marc Exp $
#

DISTNAME=	monodoc-0.13
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.org/archive/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.go-mono.org/
COMMENT=	Documentation for the Mono class libraries

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	monodoc.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
