# $NetBSD: Makefile,v 1.2 2008/03/06 14:54:09 thomasklausner Exp $
#

DISTNAME=	itask-ng-0.2.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://itask-module.googlecode.com/files/

MAINTAINER=	shinden@linux.pl
HOMEPAGE=	http://itask-module.googlecode.com/files/
COMMENT=	Application launcher and taskbar for e17

PKG_DESTDIR_SUPPORT=    	user-destdir

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
