# $NetBSD: Makefile,v 1.5 2011/02/28 14:53:18 thomasklausner Exp $
#

DISTNAME=	Pysite-0.2.0
CATEGORIES=	textproc
MASTER_SITES=	http://ambient.2y.net/pysite/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ambient.2y.net/pysite/
COMMENT=	XHTML website generation tool

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes
USE_TOOLS+=	pax

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/www && pax -rw -pp -pm . ${EGDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
