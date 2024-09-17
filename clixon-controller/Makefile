# $NetBSD$

DISTNAME=	clixon-controller-1.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=clicon/}
GITHUB_PROJECT=	clixon-controller
DISTFILES=	${PKGNAME_NOREV}.tar.gz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://www.clicon.org/
COMMENT=	Manager of network devices based on Netconf/YANG
LICENSE=	apache-2.0

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake

CLIXON_USER?=	clixon
CLIXON_GROUP?=	clixon

EGDIR=			share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	etc/clixon
INSTALLATION_DIRS+=	etc/clixon/controller
CONF_FILES+=		${EGDIR}/controller.xml \
			${PKG_SYSCONFDIR}/clixon/controller.xml
CONF_FILES+=		${EGDIR}/autocli.xml \
			${PKG_SYSCONFDIR}/clixon/controller/autocli.xml

CONFIGURE_ARGS+=	--with-cligen=${BUILDLINK_PREFIX.cligen}
CONFIGURE_ARGS+=	--with-clixon=${BUILDLINK_PREFIX.clixon}
CONFIGURE_ARGS+=	--with-clicon-user=${CLIXON_USER}
CONFIGURE_ARGS+=	--with-clicon-group=${CLIXON_GROUP}

post-install:
	cd ${WRKSRC}/src; \
		${INSTALL_DATA} controller.xml ${DESTDIR}/${PREFIX}/${EGDIR}; \
		${INSTALL_DATA} autocli.xml ${DESTDIR}/${PREFIX}/${EGDIR}

.include "../../wip/cligen/buildlink3.mk"
.include "../../wip/clixon/buildlink3.mk"
.include "../../wip/clixon-pyapi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
