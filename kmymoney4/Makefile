# $NetBSD: Makefile,v 1.3 2012/10/01 21:57:40 asau Exp $

DISTNAME=	kmymoney-4.8.3
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_KDE:=kmymoney/4.8.3/src/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	gary@duzan.org
HOMEPAGE=	https://kmymoney.org/
COMMENT=	Personal finance manager for KDE 4
LICENSE=	gnu-gpl-v2

CONFLICTS+=	kmymoney2-[0-9]*

BUILD_DEPENDS+=	automoc4-[0-9]*:../../devel/automoc4

#MAKE_JOBS_SAFE=	no
BUILD_MAKE_FLAGS+=	VERBOSE=yes

USE_CMAKE=		yes
USE_TOOLS+=		msgfmt pkg-config perl
USE_TOOLS+=		gsed
USE_TOOLS+=		gmake
EXTRACT_USING=		gtar
USE_LANGUAGES=		c c++

REPLACE_PERL+=	contrib/splitup-kde-chunk-online
REPLACE_PERL+=	contrib/fy-qif-history.pl
REPLACE_PERL+=	contrib/fy-qif.pl
REPLACE_PERL+=	kmymoney/misc/financequote.pl

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../finance/libofx/buildlink3.mk"
.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../wip/libalkimia/buildlink3.mk"
BUILDLINK_API_DEPENDS.kdelibs+=	kdelibs4>=4.5.0
.include "../../x11/kdelibs4/buildlink3.mk"
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons
.include "../../mk/bsd.pkg.mk"
