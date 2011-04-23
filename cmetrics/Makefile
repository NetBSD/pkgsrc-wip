# $NetBSD: Makefile,v 1.2 2011/04/23 20:02:41 jihbed Exp $
#

DISTNAME=	cmetrics-0.11
CATEGORIES=	devel
MASTER_SITES=	http://forge.morfeo-project.org/frs/download.php/750/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://tools.libresoft.es/cmetrics
COMMENT=	Size and complexity metrics for C source code files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	flex

DOCDIR=	${PREFIX}/share/doc/cmetrics

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
