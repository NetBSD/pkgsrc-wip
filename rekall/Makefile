# $NetBSD: Makefile,v 1.16 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=		rekall-2.2.0-beta0
PKGNAME=		${DISTNAME:S/-beta0//}
PKGREVISION=		5
CATEGORIES=		databases
MASTER_SITES=		http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rekallrevealed.org/packages/
COMMENT=		KDE database frontend


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		"PYTHONBIN=${PYTHONBIN}"

.include "../../wip/xbsql/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
