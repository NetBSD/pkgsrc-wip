# $NetBSD: Makefile,v 1.5 2010/01/18 09:38:26 thomasklausner Exp $

DISTNAME=	kmymoney2-0.9.3
PKGREVISION=	2
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmymoney2/}
EXTRACT_SUFX=  .tar.bz2

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for KDE
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt perl pkg-config bash
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIG_SHELL=		${BASH}
SHLIBTOOL_OVERRIDE=	# empty

USE_TOOLS+=		gsed

USE_TOOLS+=		autoconf

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"

CONFIGURE_ARGS+=	--enable-mt

REPLACE_PERL+=	admin/fixuifiles

BUILDLINK_DEPMETHOD.libXt?=	build

.if (${OPSYS} == "NetBSD")
BUILDLINK_ABI_DEPENDS.qt3-libs+=	qt3-libs>=3.3.8nb9
.endif

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
