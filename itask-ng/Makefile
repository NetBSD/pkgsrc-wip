# $NetBSD: Makefile,v 1.10 2012/09/30 05:44:15 asau Exp $
#

DISTNAME=	itask-ng-0.2.4
PKGREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://itask-module.googlecode.com/files/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://itask-module.googlecode.com/files/
COMMENT=	Application launcher and taskbar for e17

BUILD_DEPENDS+=			gettext-m4-[0-9]*:../../devel/gettext-m4
WRKSRC=				${WRKDIR}/itask-ng
USE_TOOLS+=			autoconf automake gmake msgfmt pkg-config
USE_LIBTOOL=			yes
GNU_CONFIGURE=			yes
BROKEN_GETTEXT_DETECTION=	yes

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/e17/buildlink3.mk"
.include "../../wip/efreet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
