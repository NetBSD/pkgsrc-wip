# $NetBSD: Makefile,v 1.3 2007/02/08 14:07:58 bartoszkuzma Exp $
#

DISTNAME=		MyServer-src-0.8.5
PKGNAME=		${DISTNAME:S/src-//}
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=myserver/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://www.myserverproject.net/
COMMENT=		Powerful and easy to configure web server

BUILD_DEFS+=		USE_INET6
BUILD_DEFS+=		VARBASE

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++ fortran
USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf autoheader automake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-root-prefix=${PREFIX}

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_INET6:M[yY][eE][sS])
CONFIGURE_ARGS+=        --enable-ipv6
.endif

.include "options.mk"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	source/server.cpp
SUBST_SED.paths=	-e "s|/etc/myserver/MIMEtypes.xml|${PKG_SYSCONFDIR}/myserver/MIMEtypes.xml|g"
SUBST_SED.paths+=	-e "s|/etc/myserver/myserver.xml|${PKG_SYSCONFDIR}/myserver/myserver.xml|g"
SUBST_SED.paths+=	-e "s|/etc/myserver/virtualhosts.xml|${PKG_SYSCONFDIR}/myserver/virtualhosts.xml|g"

SUBST_CLASSES+=		confs
SUBST_STAGE.confs=	post-patch
SUBST_FILES.confs=	binaries/virtualhosts.xml.unix.default
SUBST_SED.confs=	-e "s|/var/web/|${PREFIX}/share/myserver/web/|g"
SUBST_SED.confs+=	-e "s|/usr/local/|${PREFIX}/|g"
SUBST_SED.confs+=	-e "s|/var/log/|${VARBASE}/log/|g"

SUBST_CLASSES+=		logs
SUBST_STAGE.logs=	post-patch
SUBST_FILES.logs=	binaries/logs/Makefile.am
SUBST_SED.logs=		-e "s|.(root_prefix)/var/|${VARBASE}/|g"

EGDIR=			${PREFIX}/share/examples/myserver
CONF_FILES=		${EGDIR}/MIMEtypes.xml \
				${PKG_SYSCONFDIR}/myserver/MIMEtypes.xml
CONF_FILES+=		${EGDIR}/myserver.xml \
				${PKG_SYSCONFDIR}/myserver/myserver.xml
CONF_FILES+=		${EGDIR}/virtualhosts.xml \
				${PKG_SYSCONFDIR}/myserver/virtualhosts.xml

RCD_SCRIPTS=		myserver

pre-configure:
	cd ${WRKSRC}; aclocal -I ./m4; autoheader; \
		automake -a --foreign -i; autoconf

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/myserver

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
