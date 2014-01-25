# $NetBSD: Makefile,v 1.3 2014/01/25 10:38:13 thomasklausner Exp $

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
PYTHON_VERSIONS_INCOMPATIBLE=	33 # py-gtk2

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
