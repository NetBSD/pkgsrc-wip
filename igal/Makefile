# $NetBSD: Makefile,v 1.1.1.1 2003/07/28 11:48:26 drue Exp $
#

DISTNAME=	igal-1.4
CATEGORIES=	www graphics
MASTER_SITES=	http://jsautret.free.fr/BINS/

MAINTAINER=	drue@users.sf.net
HOMEPAGE=	http://bins.sautret.org/
COMMENT=	Online image gallery generator

DEPENDS+=	ImageMagick>=5.0:../../graphics/ImageMagick

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
REPLACE_PERL=	igal

post-patch:
	${MV} ${WRKSRC}/igal ${WRKSRC}/igal.bak
	${SED}	-e "s;@LOCALBASE@;${LOCALBASE};g" ${WRKSRC}/igal.bak > ${WRKSRC}/igal;
	${MV} ${WRKSRC}/igal.1 ${WRKSRC}/igal.1.bak
	${SED}	-e "s;@LOCALBASE@;${LOCALBASE};g" ${WRKSRC}/igal.1.bak > ${WRKSRC}/igal.1;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/igal ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/igal.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/igal
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/igal
	cd ${WRKSRC} && \
	${INSTALL_DATA} indextemplate.html slidetemplate.html tile.png igal.css ${PREFIX}/share/igal
	cd ${WRKSRC} && \
	${INSTALL_DATA} README THANKS ChangeLog COPYING ${PREFIX}/share/doc/igal

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
