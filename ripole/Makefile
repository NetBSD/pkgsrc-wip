# $NetBSD: Makefile,v 1.7 2014/10/09 14:06:30 thomasklausner Exp $
#

DISTNAME=		ripole-0.1.4
CATEGORIES=		archivers
MASTER_SITES=		http://www.pldaniels.com/ripole/

MAINTAINER=		charlie@rubberduck.com
HOMEPAGE=		http://www.pldaniels.com/ripole/
COMMENT=		Program/library designed to extract attachments from OLE2 files

USE_LIBTOOL=		yes
BUILD_TARGET=		default

INSTALLATION_DIRS=	bin

do-configure: # empty

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGBASE} ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
