# $NetBSD: Makefile,v 1.19 2010/01/18 09:38:23 thomasklausner Exp $
#

DISTNAME=		9714-gtk-qt-engine-0.2
PKGNAME=		gtk2-engines-qt-0.2
PKGREVISION=		1
CATEGORIES=		devel x11
MASTER_SITES=		http://www.kde-look.org/content/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.kde-look.org/content/show.php?content=9714
COMMENT=		GTK+ 2.x theme, which looks just like Qt toolkit

WRKSRC=			${WRKDIR}/gtk-qt-engine-0.2
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
PKGCONFIG_OVERRIDE+=	gtk-qt-engine-2.pc.in
GNU_CONFIGURE=		yes

# needed
CONFIGURE_ENV+=		PKG_CONFIG=${PREFIX}/bin/pkg-config \
			QTDIR=${QTDIR:Q}
MAKE_ENV+=		QTDIR=${QTDIR:Q}
MAKE_FLAGS+=		QTDIR=${QTDIR:Q}

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
