# $NetBSD: Makefile,v 1.4 2012/10/07 14:23:03 asau Exp $
#

DISTNAME=		ripole-0.1.4
PKGREVISION=		# empty
CATEGORIES=		archivers
MASTER_SITES=		http://www.pldaniels.com/ripole/

MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://www.pldaniels.com/ripole/
COMMENT=		a small program/library designed to pull out attachments from OLE2 data files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
BUILD_TARGET=		default

INSTALLATION_DIRS=	bin

do-configure: # empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
