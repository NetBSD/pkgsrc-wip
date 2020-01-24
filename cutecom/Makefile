# $NetBSD: Makefile,v 1.2 2012/11/17 17:31:58 othyro Exp $
#

VERSION=	0.22.0
DISTNAME=	cutecom-${VERSION}
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://cutecom.sourceforge.net/

MAINTAINER=	helgoman@users.sourceforge.net
HOMEPAGE=	http://cutecom.sourceforge.net/
COMMENT=	Graphical serial terminal
LICENSE=	gnu-gpl-v2

DEPENDS+=	lrzsz>=0.12.20:../../comms/lrzsz

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

SUBST_CLASSES+=			pkgmandir
SUBST_FILES.pkgmandir=		CMakeLists.txt
SUBST_MESSAGE.pkgmandir=	Fixing PKGMANDIR.
SUBST_STAGE.pkgmandir=		pre-configure
SUBST_SED.pkgmandir=		-e "s|share/man|${PKGMANDIR}|1"

.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
