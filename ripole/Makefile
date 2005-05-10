# $NetBSD: Makefile,v 1.1.1.1 2005/05/10 21:28:18 yeled Exp $
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
USE_PKGINSTALL=		yes
BUILD_TARGET=

do-configure: # empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
