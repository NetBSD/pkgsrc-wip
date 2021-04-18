# $NetBSD$

DISTNAME=		gnunet-gtk-0.11.7
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=gnunet/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gnunet.org/
COMMENT=		GTK user interfaces for GNUnet
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

CONFIGURE_ENV+=		LD_LIBRARY_PATH+=${BUILDLINK_PREFIX.gtk3}/lib
CONFIGURE_ARGS+=	--with-gnunet=${BUILDLINK_PREFIX.gnunet}
CONFIGURE_ARGS+=	--with-glade=${BUILDLINK_PREFIX.glade}

.include "../../devel/glade/buildlink3.mk"
.include "../../converters/qrencode/buildlink3.mk"
.include "../../wip/gnunet/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
