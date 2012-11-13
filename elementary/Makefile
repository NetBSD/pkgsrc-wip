# $NetBSD: Makefile,v 1.6 2012/11/13 20:09:29 othyro Exp $
#

DISTNAME=	elementary-0.6.0.063
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-12-02/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	E17 Widget Library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	elementary

DEPENDS+=	evas-png-[0-9]*:../../graphics/evas-png
DEPENDS+=	evas-jpeg-[0-9]*:../../graphics/evas-jpeg

MODULE_ARCH=	${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}-${LOWER_ARCH}-ver-svn-05
PLIST_SUBST=	MODULE_ARCH=${MODULE_ARCH}
PRINT_PLIST_AWK+=        { gsub(/${MODULE_ARCH}/, "$${MODULE_ARCH}") }


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
