# $NetBSD: Makefile,v 1.5 2011/12/07 20:49:29 tezdog Exp $
#

DISTNAME=	cacti-spine-0.8.7e
CATEGORIES=	net
MASTER_SITES=	http://www.cacti.net/downloads/spine/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.cacti.net/spine_info.php
COMMENT=	Spine is a poller for Cacti for large installations
LICENSE=	cacti-license
LICENSE_FILE=	${FILESDIR}/cacti-license

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	c c++
USE_LIBTOOL+=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql=${BUILDLINK_PREFIX.mysql-client:Q}
USE_TOOLS+=	automake

BUILD_DEPENDS+=	automake-[0-9]*:../../devel/automake
DEPENDS+=	cacti>=0.8.7:../../net/cacti

PKG_DESTDIR_SUPPORT=	user-destdir

CONF_FILES_PERMS+=	${EGDIR}/spine.conf.dist ${PKG_SYSCONFDIR}/spine.conf \
			${ROOT_USER} ${ROOT_GROUP} 0644

INSTALLATION_DIRS=      share/examples/cacti bin

post-extract:
	${RM} ${WRKDIR}/${DISTNAME}/config/ltmain.sh
	${LN} -s /usr/pkg/share/libtool/ltmain.sh ${WRKDIR}/${DISTNAME}/config/ltmain.sh 

pre-configure:
	cd ${WRKSRC} && \
		aclocal && \
		${PREFIX}/bin/libtoolize --force --copy && \
		autoheader && \
		autoconf && \
		automake -acf

post-install:
	${INSTALL_DATA} ${WRKSRC}/spine.conf ${EGDIR}/spine.conf.dist

.include "../../mk/mysql.buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
