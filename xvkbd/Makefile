# $NetBSD: Makefile,v 1.2 2010/08/29 04:58:41 ryo-on Exp $
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

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.if !empty(PKG_OPTIONS:Mxaw)
SUBST_CLASSES+=		xaw
SUBST_STAGE.xaw=	pre-configure
SUBST_MESSAGE.xaw=	fixing pathes
SUBST_FILES.xaw=	Imakefile
SUBST_SED.xaw=		-e 's,define XAW3D,,g'
.else
.include "../../x11/Xaw3d/buildlink3.mk"
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/xvkbd.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xvkbd.1

.include "../../mk/bsd.pkg.mk"
