# $NetBSD: Makefile,v 1.1 2007/03/06 13:01:09 cheusov Exp $

DISTNAME=	sharatype-2.0.5
PKGNAME=	a2ps-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	http://ftp.45.free.net/pub/fonts/type1/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://ftp.45.free.net/pub/fonts/type1/
COMMENT=	Cyrillic fonts for a2ps (a part of sharatype project)

DEPENDS+=	a2ps-[0-9]*:../../print/a2ps

NO_BUILD=	yes

INSTALLATION_DIRS+=	share/a2ps/afm share/a2ps/encoding share/a2ps/fonts

do-install:
	${INSTALL_DATA} ${WRKSRC}/afm/* ${PREFIX}/share/a2ps/afm
	${INSTALL_DATA} ${WRKSRC}/pfa/* ${PREFIX}/share/a2ps/fonts
	${INSTALL_DATA} ${WRKSRC}/a2ps/add/fonts.map ${PREFIX}/share/a2ps/afm/sharatype1-fonts.map
	${INSTALL_DATA} ${WRKSRC}/a2ps/replace/fonts.map ${PREFIX}/share/a2ps/afm/sharatype2-fonts.map
.for i in koi8.edf iso5.edf ms-cp1251.edf
	${INSTALL_DATA} ${WRKSRC}/a2ps/add/${i} ${PREFIX}/share/a2ps/encoding/sharatype1-${i}
	${INSTALL_DATA} ${WRKSRC}/a2ps/replace/${i} ${PREFIX}/share/a2ps/encoding/sharatype2-${i}
.endfor

.include "../../mk/bsd.pkg.mk"
