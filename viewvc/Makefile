# $NetBSD: Makefile,v 1.2 2006/07/23 02:02:16 obache Exp $
#

DISTNAME=		viewvc-1.0.1
CATEGORIES=		devel www
MASTER_SITES=		http://viewvc.tigris.org/files/documents/3330/33320/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.viewvc.org/
COMMENT=		Viewing the content of CVS/SVN repositories with a Webbrowser

NO_BUILD=		YES
PYTHON_PATCH_SCRIPTS=	viewvc-install bin/* bin/cgi/*.cgi lib/*.py

BOOTSTRAP_DEPENDS+=	wget-[0-9]*:../../net/wget
FETCH_CMD=		${PREFIX}/bin/wget

VIEWVCDIR=	share/viewvc
PLIST_SUBST+=	VIEWVCDIR=${VIEWVCDIR:Q}

CONF_FILES=	${PREFIX}/${VIEWVCDIR:Q}/viewvc.conf.dist ${PREFIX}/${VIEWVCDIR:Q}/viewvc.conf
CONF_FILES+=	${PREFIX}/${VIEWVCDIR:Q}/cvsgraph.conf.dist ${PREFIX}/${VIEWVCDIR:Q}/cvsgraph.conf

do-install:
	(cd ${WRKSRC} && \
	${PYTHONBIN} viewvc-install --prefix=${PREFIX}/${VIEWVCDIR} --destdir="")

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
