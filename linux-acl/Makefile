# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=		acl-2.2.52.src
PKGNAME=		linux-${DISTNAME:S/.src//}
CATEGORIES=		sysutils
MASTER_SITES=		http://download.savannah.nongnu.org/releases/acl/

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		https://savannah.nongnu.org/projects/acl
COMMENT=		Commands for Manipulating POSIX Access Control Lists

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
GNU_CONFIGURE=		yes
USE_TOOLS=		gmake
BUILD_TARGET=		default
INSTALL_TARGET=		install install-lib install-dev

.include "../../wip/linux-attr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
