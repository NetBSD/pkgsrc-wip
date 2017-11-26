# $NetBSD: Makefile,v 1.3 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=		attr-2.4.47.src
PKGNAME=		linux-${DISTNAME:S/.src//}
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		http://download.savannah.nongnu.org/releases/attr/

MAINTAINER=		pkgsrc@blackmouse.biz
HOMEPAGE=		https://savannah.nongnu.org/projects/attr
COMMENT=		The extended attribute package for acl

# uses linux/version.h and only tested under Linux
ONLY_FOR_PLATFORM=	Linux-*-*

WRKSRC=			${WRKDIR}/${DISTNAME:S/.src//}
GNU_CONFIGURE=		yes
USE_TOOLS=		gmake
BUILD_TARGET=		default
INSTALL_TARGET=		install install-lib install-dev

post-install:
	# Conflicts with ncurses manpages
	rm -f ${DESTDIR}${PREFIX}/man/man3/attr_get.3
	rm -f ${DESTDIR}${PREFIX}/man/man3/attr_set.3

.include "../../mk/bsd.pkg.mk"
