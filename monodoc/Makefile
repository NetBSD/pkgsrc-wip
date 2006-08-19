# $NetBSD: Makefile,v 1.4 2006/08/19 20:19:59 kristerw Exp $
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

.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
