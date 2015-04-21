# $NetBSD: Makefile,v 1.2 2015/04/21 07:21:55 krytarowski Exp $

DISTNAME=	lxqt-admin-0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	LXQt admin panel
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/liboobs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
