# $NetBSD$

DISTNAME=	wp2md-0.0.0
CATEGORIES=	textproc
GIT_REPOSITORIES=	wp2md
GIT_REPO.wp2md=		https://github.com/dreikanter/wp2md.git

WRKSRC=		${WRKDIR}/wp2md

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dreikanter/wp2md
COMMENT=	WordPress to Markdown Exporter
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	wp2md/html2text.py
REPLACE_PYTHON+=	wp2md/wp2md.py

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
