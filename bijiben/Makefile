# $NetBSD: Makefile,v 1.13 2013/06/19 12:15:39 noud4 Exp $
#

DISTNAME=	bijiben-3.20.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/bijiben/3.20/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Bijiben
COMMENT=	Simple Note Viewer
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config

.include "../../www/webkit24-gtk3/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../wip/gnome-tracker/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
