# $NetBSD: Makefile,v 1.6 2012/10/03 15:09:50 asau Exp $
#

DISTNAME=		man-1.6e
CATEGORIES=		sysutils
# the metalab should be added to bsd.sites.mk
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/doctools/man/} \
			http://primates.ximian.com/~flucifredi/man/ \
			http://www.people.fas.harvard.edu/~lucifred/man/ \
			ftp://metalab.unc.edu/pub/Linux/apps/doctools/man/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://primates.ximian.com/~flucifredi/man/
COMMENT=		Man page viewer and utilities

CONFLICTS+=		man-db-[0-9]*


USE_TOOLS+=		groff:run

PKGMANDIR?=		man
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-confdir ${PKG_SYSCONFDIR} +sgid +fhs +lang all
CONFIGURE_ARGS+=	-prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	-mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		deflocale=${PREFIX}/${PKGLOCALEDIR}/locale/

MAN_GROUP?=		man
BUILD_DEFS+=		MAN_GROUP
PKG_GROUPS=		${MAN_GROUP}

EXAMPLESDIR=		${PREFIX}/share/examples/man/
CONF_FILES=		${EXAMPLESDIR}/man.conf ${PKG_SYSCONFDIR}/man.conf

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/man.conf ${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
