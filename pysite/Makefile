# $NetBSD: Makefile,v 1.1.1.1 2003/09/29 12:24:29 marc Exp $
#

DISTNAME=	Pysite-0.2.0
CATEGORIES=	textproc
MASTER_SITES=	http://ambient.2y.net/pysite/download/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://ambient.2y.net/pysite/
COMMENT=	XHTML website generation tool

USE_BUILDLINK2=	yes
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/www && ${PAX} -rw -pp -pm . ${EGDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
