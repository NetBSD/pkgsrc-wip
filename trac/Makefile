# $NetBSD: Makefile,v 1.3 2008/05/22 15:38:48 tnn2 Exp $
#

DISTNAME=	Trac-0.11b2
PKGNAME=	${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Integrated SCM, wiki, issue tracker and project environment

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.4.1:../../wip/genshi

REPLACE_PYTHON=	cgi-bin/trac.cgi cgi-bin/trac.fcgi
REPLACE_PYTHON+=contrib/*.py contrib/*-hook contrib/workflow/*.py

.include "options.mk"

EGDIR=		share/examples/trac

INSTALLATION_DIRS+=	libexec/cgi-bin ${EGDIR}

post-install:
.for cgi in trac.cgi trac.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/${cgi} ${DESTDIR}${PREFIX}/libexec/cgi-bin
.endfor
	cd ${WRKSRC}/contrib && \
		pax -rw -pp -pm . ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
