# $NetBSD: Makefile,v 1.1.1.1 2009/05/02 17:43:07 thomasklausner Exp $
#

DISTNAME=	taglib-extras-0.1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.kollide.net/~jefferai/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kollide.net/~jefferai/
COMMENT=	Extra plugins for taglib

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/taglib-extras
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE=		taglib-extras.pc.cmake

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	taglib-extras-config.cmake
SUBST_SED.rpath=	-e "s|-L\\([^ 	]*\\)|${COMPILER_RPATH_FLAG}\\1 -L\\1|g"
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Add rpath to config script.

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
