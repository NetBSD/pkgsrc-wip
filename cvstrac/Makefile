# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:56 asau Exp $
#

DISTNAME=	cvstrac-2.0.1
CATEGORIES=	devel www
MASTER_SITES=	http://www.cvstrac.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cvstrac.org/
COMMENT=	Web-based bug and patch-set tracker for CVS, Subversion and GIT
LICENSE=	gnu-gpl-v2

.if !exists(/usr/bin/rlog)
DEPENDS+=	rcs-[0-9]*:../../devel/rcs
.endif

MAKE_FILE=		bsd-gcc.mk

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDLINK_TRANSFORM+=	rm:-lcrypt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvstrac ${DESTDIR}${PREFIX}/bin

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
