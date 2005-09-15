# $NetBSD: Makefile,v 1.6 2005/09/15 13:24:07 elvstone Exp $

DISTNAME=		lighttpd-1.4.3
CATEGORIES=		www
MASTER_SITES=		http://www.lighttpd.net/download/

MAINTAINER=		elvstone@gmail.com
HOMEPAGE=		http://www.lighttpd.net/
COMMENT=		Fast as lightning HTTP server

USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIGHTTPD_USER?=		www
LIGHTTPD_GROUP?=	www

PKG_USERS=		${LIGHTTPD_USER}:${LIGHTTPD_GROUP}::LigHTTPD\ user
PKG_GROUPS=		${LIGHTTPD_GROUP}

DOCDIR=			${PREFIX}/share/doc/lighttpd
EGDIR=			${PREFIX}/share/examples/lighttpd
WWWDIR=			${PREFIX}/share/lighttpd
LOGDIR=			${VARBASE}/log/lighttpd

RCD_SCRIPTS+=		lighttpd
PKG_SYSCONFSUBDIR?=	lighttpd

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/lighttpd

.include "options.mk"

CONF_FILES+=		${EGDIR}/lighttpd.conf ${PKG_SYSCONFDIR}/lighttpd.conf
OWN_DIRS_PERMS+=	${LOGDIR} ${LIGHTTPD_USER} ${LIGHTTPD_GROUP} 0755
REQD_DIRS+=		${WWWDIR}
REQD_FILES+=		${FILESDIR}/index.html ${WWWDIR}/index.html

post-patch:
	${SED} -e s,@@LIGHTTPD_USER@@,${LIGHTTPD_USER}, 	\
	    -e s,@@LIGHTTPD_GROUP@@,${LIGHTTPD_GROUP},		\
	    -e s,@@LOGDIR@@,${LOGDIR},				\
	    -e s,@@WWWDIR@@,${WWWDIR},				\
	    ${WRKSRC}/doc/lighttpd.conf > ${WRKSRC}/doc/lighttpd.conf.new
	${MV} ${WRKSRC}/doc/lighttpd.conf.new ${WRKSRC}/doc/lighttpd.conf

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/lighttpd.1 ${PREFIX}/man/man1/lighttpd.1
	${INSTALL_MAN} ${WRKSRC}/doc/spawn-fcgi.1 ${PREFIX}/man/man1/spawn-fcgi.1
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	for i in ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.dot; do	\
		${INSTALL_DATA} $${i} ${DOCDIR};		\
	done
	for i in AUTHORS COPYING ChangeLog NEWS README; do	\
		${INSTALL_DATA} ${WRKSRC}/$${i} ${DOCDIR};	\
	done
	for i in lighttpd.conf lighttpd.user rrdtool-graph.sh spawn-php.sh; do	\
		${INSTALL_DATA} ${WRKSRC}/doc/$${i} ${EGDIR};			\
	done

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
