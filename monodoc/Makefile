# $NetBSD: Makefile,v 1.6 2008/02/06 10:26:28 koifren Exp $

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

MAKE_JOBS_SAFE=		no

.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
