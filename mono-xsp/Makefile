# $NetBSD: Makefile,v 1.1 2008/02/13 12:40:43 koifren Exp $

DISTNAME=	xsp-1.2.6
PKGNAME=	mono-xsp-1.2.6
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/xsp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/ASP.NET
COMMENT=	Standalone web server written in C\#

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../wip/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
