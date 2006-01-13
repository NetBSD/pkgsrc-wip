# $NetBSD: Makefile,v 1.7 2006/01/13 01:24:52 rillig Exp $
#

DISTNAME=		leo-4.1-beta-4
PKGNAME=		leo-4.1beta.4
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leo/}
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://leo.sourceforge.net/
COMMENT=		Programmer's editor and a flexible browser

NO_BUILD=	yes
PYTHON_PATCH_SCRIPTS=	src/leo.py scripts/LinixInstall.py

post-extract:
	${RM} -rf ${WRKSRC:Q}/scripts/CVS

do-install:
	cd ${WRKSRC} && ${CHMOD} 755 ./install && ${SETENV} PREFIX=${PREFIX:Q} ./install && ${CHMOD} 755 ${PREFIX}/lib/leo/src/leo.py

EXTRACT_CMD_OPTS.zip=	-aqo

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
