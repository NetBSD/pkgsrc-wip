# $NetBSD: Makefile,v 1.5 2010/01/17 12:03:27 thomasklausner Exp $
#

DISTNAME=	kmldonkey-r1055884
PKGNAME=	${DISTNAME:S/-r/-2.0.5pre/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	# none, snapshot grabbed from svn
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://userbase.kde.org/KMLDonkey
COMMENT=	KDE interface for mldonkey
#LICENSE=	# TODO: (see mk/license.mk)

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/kmldonkey
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
