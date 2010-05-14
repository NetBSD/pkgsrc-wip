# $NetBSD: Makefile,v 1.1.1.1 2010/05/14 21:46:41 jihbed Exp $
#

DISTNAME=	cloc-1.51
CATEGORIES=	devel
MASTER_SITES=	http://garr.dl.sourceforge.net/project/cloc/cloc/v1.51/
EXTRACT_SUFX=	.pl

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cloc.sourceforge.net/
COMMENT=	Versatile source code counter
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_BUILD= yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cloc-1.51.pl ${DESTDIR}${PREFIX}/bin/cloc

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
