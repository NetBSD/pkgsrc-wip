# $NetBSD: Makefile,v 1.4 2004/04/15 11:03:03 jmmv Exp $
#

DISTNAME=	directory_administrator-1.5
PKGNAME=	${DISTNAME:C/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	http://diradmin.open-it.org/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://diradmin.open-it.org/
COMMENT=	Smart LDAP directory management tool

USE_BUILDLINK2=		yes
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_GNU_GETTEXT=	yes

.include "../../x11/gtk/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../databases/openldap/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
