# $NetBSD: Makefile,v 1.1.1.1 2005/02/02 07:09:25 jeremy-c-reed Exp $
#

DISTNAME=		man-1.5p
CATEGORIES=		sysutils
# the metalab should be added to bsd.sites.mk
MASTER_SITES=		${MASTER_SITE_SUNSITE:=apps/doctools/man/} \
			ftp://ftp.win.tue.nl/pub/linux-local/utils/man/ \
			ftp://metalab.unc.edu/pub/Linux/apps/doctools/man/
#			ftp://ftp.XX.kernel.org/pub/linux/utils/man/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		ftp://ftp.win.tue.nl/pub/linux-local/utils/man/
COMMENT=		Man page viewer and utilities

CONFLICTS+=		man-db-[0-9]*

#DEPENDS on groff

PKGMANDIR?=		man
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	-confdir ${PKG_SYSCONFDIR} +sgid +fhs +lang all
CONFIGURE_ARGS+=	-prefix=${PREFIX}
CONFIGURE_ARGS+=	-mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ENV+=		deflocale=${PREFIX}/${PKGLOCALEDIR}/locale/

MAN_GROUP?=		man
BUILD_DEFS=		MAN_GROUP
PKG_GROUPS=		${MAN_GROUP}

EXAMPLESDIR=		${PREFIX}/share/examples/man/
CONF_FILES=		${EXAMPLESDIR}/man.conf ${PKG_SYSCONFDIR}/man.conf

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/src/man.conf ${EXAMPLESDIR}

.include "../../mk/bsd.pkg.mk"
