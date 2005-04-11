# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:05 tvierling Exp $
#

DISTNAME=	monodoc-0.13
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.org/archive/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.go-mono.org/
COMMENT=	Documentation for the Mono class libraries

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	monodoc.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
