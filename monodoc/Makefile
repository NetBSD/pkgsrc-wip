# $NetBSD: Makefile,v 1.5 2008/02/05 17:53:17 koifren Exp $

DISTNAME=	monodoc-1.2.6
CATEGORIES=	devel
MASTER_SITES=	http://go-mono.com/sources/monodoc/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Documentation for the Mono class libraries

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	monodoc.pc.in
GNU_CONFIGURE=		yes

.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
