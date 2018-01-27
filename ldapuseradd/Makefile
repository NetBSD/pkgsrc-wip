# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:35 asau Exp $

DISTNAME=	ldapuseradd-0.9.2
CATEGORIES=	databases
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	inittab@unixdev.net
MASTER_SITES=	http://ftp.unixdev.net/pub/unixdev/ldapuseradd/0.9.2/

HOMEPAGE=	http://www.unixdev.net/projects/ldapuseradd/
COMMENT=	LDAP User/Group Management Toolset


USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
BROKEN_GETTEXT_DETECTION=	yes
CFLAGS=		-fPIC

INSTALLATION_DIRS=	sbin lib/ldapuseradd ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

.include "../../mk/bsd.prefs.mk"
.include "../../mk/compiler.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../databases/mysql56-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
