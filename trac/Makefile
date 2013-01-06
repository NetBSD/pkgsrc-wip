# $NetBSD: Makefile,v 1.16 2013/01/06 09:11:17 obache Exp $
#

DISTNAME=	Trac-1.0
PKGNAME=	${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Integrated SCM, wiki, issue tracker and project environment
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.6:../../www/py-genshi

REPLACE_PYTHON=	contrib/cgi-bin/trac.cgi contrib/cgi-bin/trac.fcgi
REPLACE_PYTHON+=contrib/*.py contrib/*-hook contrib/workflow/*.py
REPLACE_PYTHON+=trac/admin/templates/deploy_trac.* trac/tests/functional/*.py

.include "options.mk"

EGDIR=		share/examples/trac

INSTALLATION_DIRS+=	libexec/cgi-bin ${EGDIR}

post-install:
.for cgi in trac.cgi trac.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cgi-bin/${cgi} ${DESTDIR}${PREFIX}/libexec/cgi-bin
.endfor
	cd ${WRKSRC}/contrib && \
		pax -rw -pp -pm . ${DESTDIR}${PREFIX}/${EGDIR}

# deploy template files
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/trac/admin/templates/deploy_*.*cgi

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
