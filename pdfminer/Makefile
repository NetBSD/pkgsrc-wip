# $NetBSD: Makefile,v 1.4 2012/10/05 08:46:09 asau Exp $
#

DISTNAME=	pdfminer-20100424.tar
PKGNAME=	${DISTNAME:S/.tar//}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdfminer/}
EXTRACT_SUFX=	.gz#md5=d69836472cd1d555a7340e0fe75c5e20

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.unixuser.org/~euske/python/pdfminer/index.html
COMMENT=	PDF parser and analyzer
LICENSE=	mit

WRKSRC=		${WRKDIR}/pdfminer-20100424
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

DOCDIR=	${PREFIX}/share/doc/pdfminer

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/index.html ${DESTDIR}${DOCDIR}



.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
