# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 22:38:26 mpasternak Exp $
#

DISTNAME=		bacula-1.32f
PKGNAME=		${DISTNAME:S/f//}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bacula/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://bacula.sourceforge.net/
COMMENT=		Network Backup Solution

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/bacula

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
