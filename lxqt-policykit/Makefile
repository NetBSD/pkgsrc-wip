# $NetBSD: Makefile,v 1.3 2015/05/30 01:49:34 krytarowski Exp $

.include "../../wip/liblxqt/Makefile.common"

DISTNAME=	lxqt-policykit-0.9.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Policykit authentication agent
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/polkit-qt5/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
