# $NetBSD: Makefile,v 1.5 2005/07/27 16:26:13 thomasklausner Exp $
#

DISTNAME=		leo-4.1-beta-4
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leo/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://leo.sourceforge.net/
COMMENT=		Programmer's editor and a flexible browser

NO_BUILD=	# defined
PYTHON_PATCH_SCRIPTS=	src/leo.py

do-install:
	cd ${WRKSRC} && ${CHMOD} 755 ./install && env PREFIX=${PREFIX} ./install && ${CHMOD} 755 ${PREFIX}/lib/leo/src/leo.py

EXTRACT_CMD_OPTS.zip=	-aqo

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
