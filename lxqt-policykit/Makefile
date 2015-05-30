# $NetBSD: Makefile,v 1.2 2015/05/30 01:23:41 krytarowski Exp $

DISTNAME=	lxqt-policykit-0.9.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxde/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lxqt.org/
COMMENT=	Policykit authentication agent
LICENSE=	gnu-lgpl-v2.1

EXTRACT_USING=	gtar

USE_TOOLS+=	pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/polkit-qt5/buildlink3.mk"
.include "../../wip/polkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
