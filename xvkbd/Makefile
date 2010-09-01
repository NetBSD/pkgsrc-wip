# $NetBSD: Makefile,v 1.6 2010/09/01 19:25:56 ryo-on Exp $
#

DISTNAME=	xvkbd-3.2
CATEGORIES=	x11
MASTER_SITES=	http://homepage3.nifty.com/tsato/xvkbd/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://homepage3.nifty.com/tsato/xvkbd/
COMMENT=	The xvkbd is a virtual (graphical) keyboard program for X
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	yes

.include "../../mk/xaw.buildlink3.mk"
.if ${XAW_TYPE} == "standard"
SUBST_CLASSES+=		xaw
SUBST_STAGE.xaw=	pre-configure
SUBST_MESSAGE.xaw=	undefine Xaw3d
SUBST_FILES.xaw=	Imakefile
SUBST_SED.xaw=		-e 's,define XAW3D,undef XAW3D,g'
.elif ${XAW_TYPE} == "neXtaw"
SUBST_CLASSES+=		neXtaw
SUBST_STAGE.neXtaw=	pre-configure
SUBST_MESSAGE.neXtaw=	using NeXtaw3d
SUBST_FILES.neXtaw=	Imakefile
SUBST_SED.neXtaw=		-e 's,-lXaw3d,-lneXtaw,g'
.endif

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
