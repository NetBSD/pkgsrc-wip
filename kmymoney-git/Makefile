# $NetBSD: Makefile,v 1.10 2014/09/10 09:12:45 thomasklausner Exp $

DISTNAME=	kmymoney-0.0
CATEGORIES=	finance kde
MASTER_SITES=	#

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for KDE 4, Subversion Snapshot
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4

GIT_REPOSITORIES=	kmymoney
GIT_REPO.kmymoney=	git://anongit.kde.org/kmymoney.git

USE_CMAKE=		yes
USE_TOOLS+=		msgfmt pkg-config perl
USE_TOOLS+=		gsed
USE_TOOLS+=		gmake
USE_LANGUAGES=		c c++

REPLACE_PERL+=	contrib/splitup-kde-chunk-online
REPLACE_PERL+=	kmymoney/misc/financequote.pl

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
.include "../../x11/kde-baseapps4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
