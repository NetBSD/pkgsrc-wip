# $NetBSD $
#

DISTNAME=	kxmleditor-1.0.0
PKGNAME=	${DISTNAME}
PKGREVISION=	# not defined
CATEGORIES=	textproc kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kxmleditor/}

MAINTAINER=	murray@river-styx.org
HOMEPAGE=	http://kxmleditor.sourceforge.net/
COMMENT=	KDE xml editor

BUILD_USES_MSGFMT=	yes

WRKSRC=			${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
LIBTOOL_LA_FILES+=	lib/libkxmleditorpart.la

SHLIBTOOL_OVERRIDE=	libtool

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
