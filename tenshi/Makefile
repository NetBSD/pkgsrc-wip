# $NetBSD: Makefile,v 1.3 2008/05/24 15:34:15 tnn2 Exp $
#

DISTNAME=	tenshi-0.10
CATEGORIES=	sysutils
MASTER_SITES=	http://dev.inversepath.com/tenshi/

MAINTAINER=	jessepeterson@users.sourceforge.net
HOMEPAGE=	http://dev.inversepath.com/trac/tenshi
COMMENT=	Tenshi is a log monitoring program

USE_LANGUAGES=	# none

USE_TOOLS+=	perl:run
NO_BUILD=	yes
PKG_GROUPS=	tenshi
PKG_USERS=	tenshi:tenshi
EGDIR=		share/examples/${PKGBASE}
CONF_FILES=	${PREFIX}/${EGDIR}/tenshi.conf ${PKG_SYSCONFDIR}/tenshi.conf
BUILD_DEFS+=	VARBASE
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 ${EGDIR}

SUBST_CLASSES+=	tenshi
SUBST_STAGE.tenshi=	do-configure
SUBST_FILES.tenshi=	tenshi
SUBST_SED.tenshi=	-e 's,/usr/bin/perl,${PERL5},g'
SUBST_SED.tenshi+=	-e 's,/etc/tenshi/tenshi.conf,${PKG_SYSCONFDIR}/tenshi.conf,g'
SUBST_SED.tenshi+=	-e 's,/var/run/tenshi.pid,${VARBASE}/run/tenshi.pid,g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tenshi ${PREFIX}/bin/tenshi
	${INSTALL_MAN} ${WRKSRC}/tenshi.8 ${PREFIX}/${PKGMANDIR}/man8/tenshi.8
	${INSTALL_DATA} ${WRKSRC}/tenshi.conf ${PREFIX}/${EGDIR}/tenshi.conf

.include "../../mk/bsd.pkg.mk"
