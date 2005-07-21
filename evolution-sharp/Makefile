# $NetBSD: Makefile,v 1.4 2005/07/21 16:33:59 thomasklausner Exp $
#

DISTNAME=	evolution-sharp-0.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.tuwien.ac.at/z4/hci/gnome.org/sources/evolution-sharp/0.2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	ftp://ftp.tuwien.ac.at/z4/hci/gnome.org/sources/evolution-sharp/0.2/
COMMENT=	.NET language binding for various Evolution libraries

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	evolution-sharp.pc.in
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../wip/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
