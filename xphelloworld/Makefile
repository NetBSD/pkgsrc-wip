# $NetBSD: Makefile,v 1.1 2013/05/21 00:21:07 othyro Exp $
#

DISTNAME=	xphelloworld-1.0.1
CATEGORIES=	print x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Xprint sample applications
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		xaw
SUBST_FILES.xaw=	configure
SUBST_MESSAGE.xaw=	Using xax7 instead of deprecated xaw8.
SUBST_SED.xaw=		-e 's/xaw8/xaw7/g'
SUBST_STAGE.xaw=	post-patch

BUILDLINK_DEPMETHOD.libXt=	build
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../wip/libXprintAppUtil/buildlink3.mk"
.include "../../x11/libXprintUtil/buildlink3.mk"
BUILD_DEPENDS+=	xp-[0-9]*:../../x11/xp
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
