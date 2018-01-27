# $NetBSD: Makefile,v 1.11 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	gjots2-2.3.15
CATEGORIES=	x11
MASTER_SITES=	http://bhepple.freeshell.org/gjots/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bhepple.freeshell.org/gjots/
COMMENT=	Jotter application for your Gnome desktop
LICENSE=	gnu-gpl-v2

PYDISTUTILSPKG=	yes
USE_TOOLS+=	bash pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-ORBit via py-gnome2

REPLACE_BASH+=	bin/gjots2lpr

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

SUBST_CLASSES+=		mandir
SUBST_MESSAGE.mandir=	Fixing PKGMANDIR.
SUBST_FILES.mandir=	setup.py
SUBST_STAGE.mandir=	pre-configure
SUBST_SED.mandir=	-e "s|share/man|${PKGMANDIR}|1"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
