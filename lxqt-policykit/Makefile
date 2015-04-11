# $NetBSD: Makefile,v 1.1 2015/04/11 16:56:42 krytarowski Exp $

DISTNAME=	lxqt-policykit-0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/lxqt/${PKGVERSION_NOREV}/

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
