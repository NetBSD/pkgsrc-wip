# $NetBSD: Makefile,v 1.5 2012/12/27 01:00:47 tonnerre Exp $
#

DISTNAME=		syncmail
PKGNAME=		cvs-syncmail-2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cvs-syncmail/}
EXTRACT_SUFX=		# empty

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://sourceforge.net/projects/cvs-syncmail/
COMMENT=		Automatically send cvs commit messages via mail

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	syncmail
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/syncmail ${DESTDIR}${PREFIX}/bin/cvs-syncmail

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
