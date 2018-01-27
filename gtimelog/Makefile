# $NetBSD: Makefile,v 1.5 2014/05/09 07:38:43 thomasklausner Exp $

DISTNAME=	gtimelog-0.5.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gtimelog/}

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://mg.pov.lt/gtimelog/
COMMENT=	Small Gtk+ app for keeping track of your time
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

REPLACE_PYTHON+=		src/gtimelog/main.py src/gtimelog/test_gtimelog.py scripts/*.py
PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
