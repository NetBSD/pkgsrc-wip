# $NetBSD: Makefile,v 1.2 2005/04/11 21:11:55 tvierling Exp $
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
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../wip/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
