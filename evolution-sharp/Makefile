# $NetBSD: Makefile,v 1.7 2006/08/19 20:19:59 kristerw Exp $
#

DISTNAME=	evolution-sharp-0.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-sharp/0.2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GNOME:=sources/evolution-sharp/0.2/}
COMMENT=	.NET language binding for various Evolution libraries

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	evolution-sharp.pc.in
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../x11/gtk2-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
