# $NetBSD: Makefile,v 1.6 2004/05/07 01:57:52 xtraeme Exp $
#

DISTNAME=	directory_administrator-1.5
PKGNAME=	${DISTNAME:C/_/-/}
CATEGORIES=	sysutils
MASTER_SITES=	http://diradmin.open-it.org/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://diradmin.open-it.org/
COMMENT=	Smart LDAP directory management tool

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome1-1.5
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_GNU_GETTEXT=	yes

.include "../../x11/gtk/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
