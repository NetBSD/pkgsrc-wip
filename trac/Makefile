# $NetBSD: Makefile,v 1.14 2011/02/13 11:02:01 obache Exp $
#

DISTNAME=	Trac-0.12.2
PKGNAME=	${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Integrated SCM, wiki, issue tracker and project environment
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.6:../../www/py-genshi

REPLACE_PYTHON=	cgi-bin/trac.cgi cgi-bin/trac.fcgi
REPLACE_PYTHON+=contrib/*.py contrib/*-hook contrib/workflow/*.py
REPLACE_PYTHON+=trac/admin/templates/deploy_trac.* trac/tests/functional/*.py

.include "options.mk"

EGDIR=		share/examples/trac

INSTALLATION_DIRS+=	libexec/cgi-bin ${EGDIR}

post-install:
.for cgi in trac.cgi trac.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/${cgi} ${DESTDIR}${PREFIX}/libexec/cgi-bin
.endfor
	cd ${WRKSRC}/contrib && \
		pax -rw -pp -pm . ${DESTDIR}${PREFIX}/${EGDIR}

# deploy template files
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/trac/admin/templates/deploy_*.*cgi

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
