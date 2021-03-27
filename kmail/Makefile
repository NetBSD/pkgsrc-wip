# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kmail-${KAPPSVER}
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	KDE mail client
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	akonadi-import-wizard>=${KAPPSVER}:../../wip/akonadi-import-wizard
DEPENDS+=	kmail-account-wizard>=${KAPPSVER}:../../wip/kmail-account-wizard
DEPENDS+=	mbox-importer>=${KAPPSVER}:../../wip/mbox-importer
DEPENDS+=	pim-data-exporter>=${KAPPSVER}:../../wip/pim-data-exporter
DEPENDS+=	pim-sieve-editor>=${KAPPSVER}:../../wip/pim-sieve-editor

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../wip/kdepim-runtime/buildlink3.mk"
.include "../../wip/kontactinterface/buildlink3.mk"
.include "../../wip/libksieve/buildlink3.mk"
.include "../../wip/mailcommon/buildlink3.mk"
.include "../../wip/ktnef/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
