# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:28 thomasklausner Exp $
#

DISTNAME=		panda-0.5.4
PKGREVISION=		1
CATEGORIES=		print
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=panda/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.stillhq.com//panda/
COMMENT=			GPLed PDF generation library

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/panda.pc.in
GNU_CONFIGURE=		yes

# THIS package is broken, when creating the library it checks for the real
# installation path, not the sources one. and this crashes in compilation
# when the library is yet installed in the system.
#
# ugly fix to fix an ugly ln -s from the author
#
# - bugs reported - hope to drop this in the next version
post-extract:
	rm -f ${WRKSRC}/config/config.* ${WRKSRC}/config/ltmain.sh
	cp ${FILESDIR}/* ${WRKSRC}/config/

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../databases/edb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
