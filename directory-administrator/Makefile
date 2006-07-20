# $NetBSD: Makefile,v 1.11 2006/07/20 20:06:17 thomasklausner Exp $
#

DISTNAME=	directory_administrator-1.5
PKGNAME=	${DISTNAME:C/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	http://diradmin.open-it.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diradmin.open-it.org/
COMMENT=	Smart LDAP directory management tool

USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/openldap-client/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
