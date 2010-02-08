# $NetBSD: Makefile,v 1.3 2010/02/08 20:41:29 thomasklausner Exp $

DISTNAME=	kmymoney
CATEGORIES=	finance kde
MASTER_SITES=	#

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for KDE 4, Subversion Snapshot
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4

SVN_REPOSITORIES=	kmymoney
SVN_ROOT.kmymoney=	svn://anonsvn.kde.org/home/kde/trunk/playground/office/kmymoney
NO_CHECKSUM=YES

#MAKE_JOBS_SAFE=no

USE_CMAKE=		yes
USE_TOOLS+=		msgfmt pkg-config perl
USE_TOOLS+=		gsed
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

REPLACE_PERL+=	contrib/splitup-kde-chunk-online

.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/glibmm/buildlink3.mk"
.include "../../finance/libofx/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../misc/kdepim4/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/kdebase4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
