# $NetBSD: Makefile,v 1.13 2008/11/08 00:32:18 thomasklausner Exp $
#

DISTNAME=	evolution-sharp-0.18.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/evolution-sharp/0.18/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GNOME:=sources/evolution-sharp/0.18/}
COMMENT=	.NET language binding for various Evolution libraries

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	evolution-sharp.pc.in
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

.include "../../lang/mono/buildlink3.mk"
BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=2.24.0
BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server<2.25.0
.include "../../mail/evolution-data-server/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk-sharp+=	gtk-sharp>=2.12.5
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
