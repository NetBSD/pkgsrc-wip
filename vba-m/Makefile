# $NetBSD: Makefile,v 1.1.1.1 2011/12/28 06:56:35 othyro Exp $
#

PKGVERSION=	1.8.0.1054
DISTNAME=	vbam-${PKGVERSION}-src
PKGNAME=	vba-m-${PKGVERSION}
CATEGORIES=	emulators
MASTER_SITES=	http://sourceforge.net/projects/vbam/files/VBA-M%20svn%20r1054/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vba-m.com/
COMMENT=	VBA-M is a fork from the now inactive VisualBoy Advance project
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/vbam-${PKGVERSION_NOREV}
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
CMAKE_ARGS+=	-DVERSION=${PKGVERSION}
CMAKE_ARGS+=	-DENABLE_WX=OFF # "wx is not even beta state at present"
CMAKE_ARGS+=	-DSYSCONFDIR=${PKG_SYSCONFDIR}
EGDIR=		${PREFIX}/share/examples/vbam
CONF_FILES+=	${EGDIR}/vbam.cfg ${PKG_SYSCONFDIR}/vbam.cfg

.include "options.mk"

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
#.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../audio/openal/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../net/libdnet/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
