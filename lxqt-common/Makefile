# $NetBSD: Makefile,v 1.2 2015/05/02 23:31:37 krytarowski Exp $

DISTNAME=	lxqt-common-0.9.1
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Common data file required for running an lxde-qt session
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
