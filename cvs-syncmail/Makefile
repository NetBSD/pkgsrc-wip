# $NetBSD: Makefile,v 1.2 2005/04/11 21:10:47 tvierling Exp $
#

DISTNAME=		syncmail
PKGNAME=		cvs-syncmail-2.1
CATEGORIES=		devel
MASTER_SITES=		http://optusnet.dl.sourceforge.net/sourceforge/cvs-syncmail/
EXTRACT_SUFX=		# empty

MAINTAINER=		roland.illig@gmx.de
HOMEPAGE=		http://optusnet.dl.sourceforge.net/sourceforge/cvs-syncmail/
COMMENT=		Automatically send cvs commit messages via mail

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	syncmail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/syncmail ${PREFIX}/bin/cvs-syncmail

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
