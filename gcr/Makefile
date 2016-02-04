# $NetBSD: Makefile,v 1.67 2015/12/05 21:26:08 adam Exp $

DISTNAME=		gcr-3.18.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcr/3.18/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Library for crypto UI and related tasks
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
USE_LIBTOOL=		YES

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/p11-kit/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.12
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
