# $NetBSD: Makefile,v 1.5 2010/06/26 16:59:36 cheusov Exp $

DISTNAME=	sharatype-2.0.5
PKGNAME=	a2ps-${DISTNAME}
CATEGORIES=	print
MASTER_SITES=	http://ftp.wagner.pp.ru/pub/fonts/type1/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://ftp.wagner.pp.ru/pub/fonts/type1/
COMMENT=	Cyrillic fonts for a2ps (a part of sharatype project)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		a2ps-[0-9]*:../../print/a2ps

NO_BUILD=		yes

PKGDOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS+=	share/a2ps/afm share/a2ps/encoding share/a2ps/fonts
INSTALLATION_DIRS+=	${PKGDOCDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/afm/* ${DESTDIR}${PREFIX}/share/a2ps/afm
	${INSTALL_DATA} ${WRKSRC}/pfa/* ${DESTDIR}${PREFIX}/share/a2ps/fonts
	${INSTALL_DATA} ${WRKSRC}/a2ps/add/fonts.map ${DESTDIR}${PREFIX}/share/a2ps/afm/sharatype1-fonts.map
	${INSTALL_DATA} ${WRKSRC}/a2ps/replace/fonts.map ${DESTDIR}${PREFIX}/share/a2ps/afm/sharatype2-fonts.map
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PKGDOCDIR}/
.for i in koi8.edf iso5.edf ms-cp1251.edf
	${INSTALL_DATA} ${WRKSRC}/a2ps/add/${i} ${DESTDIR}${PREFIX}/share/a2ps/encoding/sharatype1-${i}
	${INSTALL_DATA} ${WRKSRC}/a2ps/replace/${i} ${DESTDIR}${PREFIX}/share/a2ps/encoding/sharatype2-${i}
.endfor

.include "../../mk/bsd.pkg.mk"
