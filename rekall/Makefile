# $NetBSD: Makefile,v 1.4 2004/04/26 02:19:06 blef Exp $
#

DISTNAME=		rekall-2.2.0-beta0
PKGNAME=		${DISTNAME:S/-beta0//}
CATEGORIES=		databases
MASTER_SITES=		http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.rekallrevealed.org/packages/
COMMENT=		KDE database frontend

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		"PYTHONBIN=${PYTHONBIN}"

.include "../../wip/xbsql/buildlink3.mk"
.include "../../databases/mysql4-client/buildlink3.mk"
.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
