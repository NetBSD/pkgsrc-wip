# $NetBSD: Makefile,v 1.3 2004/02/17 02:55:42 blef Exp $
#

DISTNAME=		9714-gtk-qt-engine-0.2
PKGNAME=		gtk2-engines-qt-0.2
WRKSRC=			${WRKDIR}/gtk-qt-engine-0.2
CATEGORIES=		wip
MASTER_SITES=		http://www.kde-look.org/content/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.kde-look.org/content/show.php?content=9714
COMMENT=		GTK+ 2.x theme, which looks just like Qt toolkit

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gtk-qt-engine-2.pc.in
GNU_CONFIGURE=		yes

# needed
CONFIGURE_ENV+=		PKG_CONFIG=${PREFIX}/bin/pkg-config \
			QTDIR=${QTDIR}
MAKE_ENV+=		QTDIR=${QTDIR}
MAKE_FLAGS+=		QTDIR=${QTDIR}

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
