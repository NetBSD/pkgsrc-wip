## $NetBSD$

DISTNAME=	ardour-4.4
CATEGORIES=	audio

GIT_REPOSITORIES=ardour
GIT_REPO.ardour=git://git.ardour.org/ardour/ardour.git

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Digital Audio Workstation
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/ardour-4.4
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libs/gtkmm2ext/libgtkmm2ext.pc.in
PKGCONFIG_OVERRIDE+=	libs/midi++2/libmidi++.pc.in
PKGCONFIG_OVERRIDE+=	libs/pbd/libpbd.pc.in

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
