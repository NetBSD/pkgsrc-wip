# $NetBSD: Makefile,v 1.3 2006/05/01 01:32:08 shattered Exp $
#

DISTNAME=	monodoc-0.13
CATEGORIES=	devel
MASTER_SITES=	http://www.go-mono.org/archive/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Documentation for the Mono class libraries

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	monodoc.pc.in
GNU_CONFIGURE=		yes

.include "../../wip/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
