# $NetBSD: Makefile,v 1.1.1.1 2003/11/25 23:14:23 mpasternak Exp $
#

DISTNAME=		leo-4.1-beta-4
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=leo/}
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://leo.sourceforge.net/
COMMENT=		Programmer's editor and a flexible browser

USE_BUILDLINK2=		yes
NO_BUILD=	# defined
PYTHON_PATCH_SCRIPTS=	src/leo.py

do-install:
	cd ${WRKSRC} && ${CHMOD} 755 ./install && env PREFIX=${PREFIX} ./install && ${CHMOD} 755 ${PREFIX}/lib/leo/src/leo.py

# I wrote about this on tech-pkg@
# after freeze it should not be needed. mind how -L changes case of filenames
EXTRACT_CMD=		${LOCALBASE}/bin/unzip -aqo $${extract_file}

.include "../../lang/python/application.mk"
.include "../../x11/py-Tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
