# $NetBSD: Makefile,v 1.1 2004/08/10 21:30:12 rillig Exp $
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
USE_BUILDLINK3=		yes
EXTRACT_CMD=		${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}
NO_BUILD=		yes
PYTHON_PATCH_SCRIPTS=	syncmail

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/syncmail ${PREFIX}/bin/cvs-syncmail

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
