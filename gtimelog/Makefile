# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:40 asau Exp $
#

DISTNAME=	gtimelog-0.5.0
CATEGORIES=	time
MASTER_SITES=	http://pypi.python.org/packages/source/g/gtimelog/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://mg.pov.lt/gtimelog/
COMMENT=	Small Gtk+ app for keeping track of your time
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_PATCH_SCRIPTS+=	src/gtimelog/main.py src/gtimelog/test_gtimelog.py scripts/*.py

PYDISTUTILSPKG= yes

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
