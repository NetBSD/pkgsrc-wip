# $NetBSD: Makefile,v 1.6 2013/05/10 08:20:04 ahp-nils Exp $
#

DISTNAME=	uptimed-0.3.17
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=rpodgorny/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=		joe@joe.cz
HOMEPAGE=		https://github.com/rpodgorny/uptimed
COMMENT=		Keeps track of current and past system uptimes


USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS=	bin sbin lib ${PKGMANDIR}/man2 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/examples/rc.d ${EGDIR}

RCD_SCRIPTS=		uptimed
CONF_FILES=		${EGDIR}/uptimed.conf-dist ${PKG_SYSCONFDIR}/uptimed.conf

.include "../../mk/bsd.pkg.mk"
