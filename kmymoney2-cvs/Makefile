# $NetBSD: Makefile,v 1.1 2009/06/06 17:20:52 gduzan Exp $

DISTNAME=	kmymoney2-0.9.3
PKGREVISION=	${_CVS_PKGVERSION:S/.//g}
CATEGORIES=	finance kde
MASTER_SITES=	#

MAINTAINER=	gary@duzan.org
HOMEPAGE=	http://kmymoney2.sourceforge.net/
COMMENT=	Personal finance manager for KDE
WRKSRC=		${WRKDIR}/kmymoney2
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake msgfmt perl pkg-config bash
USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
CONFIG_SHELL=		${BASH}
SHLIBTOOL_OVERRIDE=	# empty

USE_TOOLS+=		gsed

USE_TOOLS+=		autoconf automake

pre-configure:
	set -e; cd ${WRKSRC} && SHELL=${BASH} ${GMAKE} -f Makefile.dist

.include "options.mk"

CONFIGURE_ARGS+=	--enable-mt

REPLACE_PERL+=	admin/fixuifiles
#REPLACE_BASH+=	admin/missing

BUILDLINK_DEPMETHOD.libXt?=	build

.if (${OPSYS} == "NetBSD")
BUILDLINK_ABI_DEPENDS.qt3-libs+=	qt3-libs>=3.3.8nb9
.endif

CVS_ROOT.kmymoney2=	:pserver:anonymous@kmymoney2.cvs.sourceforge.net:/cvsroot/kmymoney2
CVS_REPOSITORIES=	kmymoney2

.include "../../wip/mk/cvs-package.mk"

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
