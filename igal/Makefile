# $NetBSD: Makefile,v 1.10 2008/08/18 18:35:48 ficovh Exp $
#
DISTNAME=	igal-1.4.7-wt
CATEGORIES=	www graphics
MASTER_SITES=	http://trexler.at/igal/

MAINTAINER=	drue@users.sf.net
HOMEPAGE=	http://trexler.at/igal/
COMMENT=	Online image gallery generator

DEPENDS+=	ImageMagick>=5.0:../../graphics/ImageMagick

NO_CONFIGURE=		YES
NO_BUILD=		YES
REPLACE_PERL=		igal
USE_TOOLS+=		perl:run
USE_PKGLOCALEDIR=	YES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igal ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/igal.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/igal
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/igal
	cd ${WRKSRC} && \
	${INSTALL_DATA} indextemplate.html slidetemplate.html tile.png igal.css ${PREFIX}/share/igal
	cd ${WRKSRC} && \
	${INSTALL_DATA} README THANKS ChangeLog COPYING ${PREFIX}/share/doc/igal

.include "../../mk/bsd.pkg.mk"
