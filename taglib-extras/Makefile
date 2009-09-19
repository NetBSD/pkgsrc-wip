# $NetBSD: Makefile,v 1.6 2009/09/19 13:39:53 thomasklausner Exp $
#

DISTNAME=	taglib-extras-1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://www.kollide.net/~jefferai/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kollide.net/~jefferai/
COMMENT=	Extra plugins for taglib

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE=		taglib-extras.pc.cmake

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	taglib-extras-config.cmake
SUBST_SED.rpath=	-e "s|-L\\([^ 	]*\\)|${COMPILER_RPATH_FLAG}\\1 -L\\1|g"
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Add rpath to config script.

.include "options.mk"

BUILDLINK_ABI_DEPENDS.taglib+=	taglib>=1.6
.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
