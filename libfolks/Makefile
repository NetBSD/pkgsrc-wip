# $NetBSD: Makefile,v 1.10 2014/10/25 19:00:14 prlw1 Exp $
#

DISTNAME=	folks-0.10.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/folks/0.10/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Folks
COMMENT=	Library to manage contacts
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool gmake msgfmt
USE_PKGLOCALEDIR=	yes


PKGCONFIG_OVERRIDE+=	lib/pkgconfig/folks-dummy.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/folks-telepathy.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/folks.pc

# XXX disabled because this blocks the build, unclear why
CONFIGURE_ARGS+=	--enable-eds-backend=no

TEST_TARGET=	check

CPPFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../wip/evolution-data-server/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
