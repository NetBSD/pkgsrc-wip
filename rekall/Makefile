# $NetBSD: Makefile,v 1.1.1.1 2003/11/18 07:31:23 mpasternak Exp $
#

DISTNAME=		rekall-2.2.0-beta0
PKGNAME=		${DISTNAME:S/-beta0//}
CATEGORIES=		databases
MASTER_SITES=		http://www.rekallrevealed.org/packages/
EXTRACT_SUFX=		.tgz

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.rekallrevealed.org/packages/
COMMENT=		KDE database frontend

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		"PYTHONBIN=${PYTHONBIN}"

.include "../../wip/xbsql/buildlink2.mk"
.include "../../wip/mysql4-client/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/kdelibs3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
