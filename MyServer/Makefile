# $NetBSD: Makefile,v 1.1.1.1 2006/09/13 13:55:07 bartoszkuzma Exp $
#

DISTNAME=		MyServer-src-0.8.2
PKGNAME=		${DISTNAME:S/src-//}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=myserverweb/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.myserverproject.net/
COMMENT=		Powerful and easy to configure web server

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=		c++
USE_LANGUAGES+=		fortran
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	source/server.cpp
SUBST_SED.paths=	-e "s|/etc/myserver/MIMEtypes.xml|${PKG_SYSCONFDIR}/myserver/MIMEtypes.xml|g"
SUBST_SED.paths+=	-e "s|/etc/myserver/myserver.xml|${PKG_SYSCONFDIR}/myserver/myserver.xml|g"
SUBST_SED.paths+=	-e "s|/etc/myserver/virtualhosts.xml|${PKG_SYSCONFDIR}/myserver/virtualhosts.xml|g"

EGDIR=			${PREFIX}/share/examples/myserver
CONF_FILES=		${EGDIR}/MIMEtypes.xml \
			${PKG_SYSCONFDIR}/myserver/MIMEtypes.xml
CONF_FILES+=		${EGDIR}/myserver.xml \
			${PKG_SYSCONFDIR}/myserver/myserver.xml
CONF_FILES+=		${EGDIR}/virtualhosts.xml \
			${PKG_SYSCONFDIR}/myserver/virtualhosts.xml

RCD_SCRIPTS=		myserver

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/myserver

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
