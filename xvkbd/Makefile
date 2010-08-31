# $NetBSD: Makefile,v 1.4 2010/08/31 09:17:01 ryo-on Exp $
#

DISTNAME=	xvkbd-3.2
CATEGORIES=	x11
MASTER_SITES=	http://homepage3.nifty.com/tsato/xvkbd/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://homepage3.nifty.com/tsato/xvkbd/
COMMENT=	The xvkbd is a virtual (graphical) keyboard program for X
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PKG_OPTIONS_VAR=	PKG_OPTIONS.xvkbd
PKG_SUPPORTED_OPTIONS=	xaw

.include "../../mk/bsd.options.mk"

USE_IMAKE=	yes

.if !empty(PKG_OPTIONS:Mxaw) || (defined(XAW_TYPE) && ${XAW_TYPE} == "standard")
SUBST_CLASSES+=		xaw
SUBST_STAGE.xaw=	pre-configure
SUBST_MESSAGE.xaw=	fixing pathes
SUBST_FILES.xaw=	Imakefile
SUBST_SED.xaw=		-e 's,define XAW3D,,g'

.include "../../x11/libXaw/buildlink3.mk"
.else
.include "../../x11/Xaw3d/buildlink3.mk"
.endif

.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
