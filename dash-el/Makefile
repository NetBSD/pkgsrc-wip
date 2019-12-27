# $NetBSD$

DISTNAME=	dash.el-2.16.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=magnars/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/magnars/dash.el/releases/tag/ # TODO: check
COMMENT=	Modern list api for Emacs. No 'cl required
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes

INSTALLATION_DIRS=	${PREFIX}/share/emacs/site-lisp/dash

do-install:
	${INSTALL} ${WRKSRC}/dash.el ${DESTDIR}${PREFIX}/share/emacs/site-lisp/dash

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
