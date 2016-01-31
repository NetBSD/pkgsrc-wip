# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kdoctools-${KF5VER}
CATEGORIES=	misc

HOMEPAGE=	https://projects.kde.org/projects/frameworks/kdoctools
COMMENT=	Documentation generation from docbook
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	perl

BUILD_DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../wip/karchive/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
