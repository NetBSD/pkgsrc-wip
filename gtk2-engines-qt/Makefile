# $NetBSD: Makefile,v 1.7 2004/08/17 18:27:44 tvierling Exp $
#

DISTNAME=		9714-gtk-qt-engine-0.2
PKGNAME=		gtk2-engines-qt-0.2
WRKSRC=			${WRKDIR}/gtk-qt-engine-0.2
CATEGORIES=		devel x11
MASTER_SITES=		http://www.kde-look.org/content/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.kde-look.org/content/show.php?content=9714
COMMENT=		GTK+ 2.x theme, which looks just like Qt toolkit

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/gtk-2.0/2.4.0/engines/libqtengine.la
USE_GNU_TOOLS+=		make
PKGCONFIG_OVERRIDE+=	gtk-qt-engine-2.pc.in
GNU_CONFIGURE=		yes

# needed
CONFIGURE_ENV+=		PKG_CONFIG=${PREFIX}/bin/pkg-config \
			QTDIR=${QTDIR}
MAKE_ENV+=		QTDIR=${QTDIR}
MAKE_FLAGS+=		QTDIR=${QTDIR}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
