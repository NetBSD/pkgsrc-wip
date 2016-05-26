# $NetBSD: Makefile,v 1.13 2013/06/19 12:15:39 noud4 Exp $
#

DISTNAME=	gnome-todo-3.20.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-todo/3.20/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.gnome.org/browse/gnome-todo/
COMMENT=	Personal task manager for GNOME
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config

.include "../../net/gnome-online-accounts/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libpeas/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
