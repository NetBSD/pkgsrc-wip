# $NetBSD: Makefile,v 1.8 2006/11/25 11:50:59 shattered Exp $
#

DISTNAME=	igal-1.4
CATEGORIES=	www graphics
MASTER_SITES=	http://nanoheat.stanford.edu/epop/igal/

MAINTAINER=	drue@users.sf.net
HOMEPAGE=	http://nanoheat.stanford.edu/epop/igal/
COMMENT=	Online image gallery generator

DEPENDS+=	ImageMagick>=5.0:../../graphics/ImageMagick

NO_CONFIGURE=		YES
NO_BUILD=		YES
REPLACE_PERL=		igal
USE_TOOLS+=		perl:run
USE_PKGLOCALEDIR=	YES

post-patch:
	${MV} ${WRKSRC}/igal ${WRKSRC}/igal.bak
	${SED}	-e "s;@LOCALBASE@;${LOCALBASE};g" ${WRKSRC}/igal.bak > ${WRKSRC}/igal;
	${MV} ${WRKSRC}/igal.1 ${WRKSRC}/igal.1.bak
	${SED}	-e "s;@LOCALBASE@;${LOCALBASE};g" ${WRKSRC}/igal.1.bak > ${WRKSRC}/igal.1;

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
