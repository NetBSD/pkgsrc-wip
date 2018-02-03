# $NetBSD: Makefile,v 1.69 2017/12/08 08:52:58 maya Exp $

DISTNAME=	kdialog-${KAPPSVER}
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE utility for displaying dialog boxes from shell scripts
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
