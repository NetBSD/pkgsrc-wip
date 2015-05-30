# $NetBSD: Makefile,v 1.3 2015/05/30 01:23:41 krytarowski Exp $

DISTNAME=	lxqt-runner-0.9.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Launch applications quickly by typing commands
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../wip/lxqt-globalkeys/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
