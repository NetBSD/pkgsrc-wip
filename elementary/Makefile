# $NetBSD: Makefile,v 1.4 2010/01/18 19:41:05 jsonn Exp $
#

DISTNAME=	elementary-0.6.0.063
CATEGORIES=	x11
MASTER_SITES=	http://download.enlightenment.org/snapshots/2009-12-02/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.enlightenment.org/
COMMENT=	E17 Widget Library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE=	elementary

DEPENDS+=	evas-png-[0-9]*:../../graphics/evas-png
DEPENDS+=	evas-jpeg-[0-9]*:../../graphics/evas-jpeg

MODULE_ARCH=	${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}-${LOWER_ARCH}-ver-svn-05
PLIST_SUBST=	MODULE_ARCH=${MODULE_ARCH}
PRINT_PLIST_AWK+=        { gsub(/${MODULE_ARCH}/, "$${MODULE_ARCH}") }

.include "../../wip/ecore/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
