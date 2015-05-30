# $NetBSD: Makefile,v 1.5 2015/05/30 01:23:41 krytarowski Exp $

DISTNAME=	lxqt-globalkeys-0.9.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Daemon and library for global keyboard shortcuts registration
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
