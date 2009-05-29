# $NetBSD: Makefile,v 1.1 2009/05/29 01:26:19 gduzan Exp $

DISTNAME=	kmymoney2-0.9.3
#PKGREVISION=	4
CATEGORIES=	finance kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kmymoney2/}
EXTRACT_SUFX=  .tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for KDE

USE_TOOLS+=		gmake msgfmt perl pkg-config bash
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIG_SHELL=		${BASH}
SHLIBTOOL_OVERRIDE=	# empty

USE_TOOLS+=		gsed
#_TOOLS_USE_PKGSRC.gsed=yes

INSTALL_UNSTRIPPED=YES

.include "options.mk"

CONFIGURE_ARGS+=	--enable-mt

USE_TOOLS+=		autoconf

pre-configure:
	cd ${WRKSRC} && autoconf

#CONFIGURE_ARGS+=	--enable-debug
#INSTALL_UNSTRIPPED=yes

REPLACE_PERL+=	admin/fixuifiles

# a fix for qt-3.3.5, please remove if qt-3.3.6 (or newer) solves the problem
#SUBST_CLASSES+=		hints
#SUBST_STAGE.hints=	post-patch
#SUBST_MESSAGE.hints=	Fix includehints.
#SUBST_FILES.hints=	kmymoney2/dialogs/*.ui kmymoney2/views/*.ui
#SUBST_FILTER_CMD.hints=	${GREP} -v includehint

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
