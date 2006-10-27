# $NetBSD: Makefile,v 1.1.1.1 2006/10/27 22:30:56 thomasklausner Exp $
#

DISTNAME=	tesseract-1.02
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tesseract-ocr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tesseract-ocr.sourceforge.net/
COMMENT=	Commercial quality open source OCR engine

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c++

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/tesseract.sh \
		> ${WRKSRC}/tesseract.sh

post-install:
	${MV} ${PREFIX}/bin/tesseract ${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/tesseract.sh ${PREFIX}/bin/tesseract
	cd ${WRKSRC} && ${PAX} -pp -rw tessdata ${PREFIX}/libexec
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tesseract
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tesseract

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
