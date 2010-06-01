# $NetBSD: Makefile,v 1.1 2010/06/01 21:15:06 mwdavies Exp $

DISTNAME=	k4dirstat-2.7.0
CATEGORIES=	sysutils

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://grumpypenguin.org
COMMENT=	Graphical disk usage utility

GIT_REPOSITORIES=	master
GIT_REPO.master=	http://grumpypenguin.org/~josh/kdirstat.git
.include "../../wip/mk/git-package.mk"
_GIT_FLAGS= #

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=	perl msgfmt
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/kdirstat

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdebase4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
