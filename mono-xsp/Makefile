# $NetBSD: Makefile,v 1.2 2008/02/13 13:10:50 koifren Exp $

DISTNAME=	xsp-${MONO_VERSION}
PKGNAME=	mono-xsp-${MONO_VERSION}
CATEGORIES=	www
MASTER_SITES=	http://go-mono.com/sources/xsp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kefren@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/ASP.NET
COMMENT=	Standalone web server written in C\#

.include "../../wip/mono/Makefile.common"

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../wip/mono/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
